//第一次发帖，代码再次重新发一下
#include "common.h"
//common中含头文件和 模拟缓冲区的结构体s_client
/*
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <semaphore.h>

typedef struct s_client
{
    int clientid;//数值
    int status;//标示是否有值，有值=1，无值=0
};
*/

//main.c
#define MAX_CONSUMERS 5 //消费线程数
#define MAX_PRODUCERS 5 //生产线程数
#define MAX_BUFFERS 20 //缓冲区可存数据
#define MAX_NUMBER 500 //生产总数

FILE *fp, *fp_out, *fp_in;//可无视，in.txt 与 123.txt 结合stdout 可看出问题点buff内数据>2

pthread_mutex_t full_mutex,empty_mutex,file_mutex;
//分别为消费、生产、缓冲区互斥锁

volatile int buff_counts = 0,  exit_flag = 0, i_in = 0, exit_flag_consumer = 0;
//exit_flag、exit_flag_consumer分别为生产、消费线程退出条件，i_in 取值 1至500

volatile struct s_client buff[MAX_BUFFERS]; //读写缓冲区

//生产者写缓冲区
int write_one(volatile struct s_client *buffer, int num)
{
int i,j,sum=0;

//遍历，将未被读取的数据置前
    for(i=0;i<MAX_BUFFERS;i++)
{
        if(buffer[i].status) continue;
        
        for(j=i+1;j<MAX_BUFFERS;j++)
        {
            if(buffer[j].status )
            {
                buffer[i].status = 1;
                buffer[i].clientid = buffer[j].clientid;
                buffer[j].status = 0;
                buffer[j].clientid = 0;
            }
        }
}
    for(i=0;i<MAX_BUFFERS;i++)
{
if(buffer[i].status == 0 )
        {
            buffer[i].clientid = num;
            buffer[i].status = 1;
            fprintf(fp_in, "buffer[%d].clientid = %d\n",i,num);
            break;
        }
    }
    return 0;
}

//消费者读缓冲区
int get_one(volatile struct s_client *buffer)
{
int i,num = -1;
    for(i = 0; i < MAX_BUFFERS; i++)
{
if(buffer[i].status)
        {
            num = buffer[i].clientid ;
            buffer[i].status = 0;
            //fprintf(fp_in, "buffer[%d].clientid = %d\n",i,num);
            break;
        }
        //return -1;
}
    return num;
}

//生产者线程
int producer()
{
 
    printf("%4d produce is begain\n", pthread_self()%10000);
    fprintf(fp_out, "%4d produce is begain\n", pthread_self()%10000);
    while(1)
    {
        pthread_mutex_lock(&empty_mutex);
        while(buff_counts<MAX_BUFFERS)
        {
            i_in++;
            if(i_in>MAX_NUMBER || exit_flag)
            {
                exit_flag = 1;
                break;
            }

            pthread_mutex_lock(&file_mutex);
            fprintf(fp,"%d\n", i_in);
            //fflush(fp);
write_one(buff, i_in);
            buff_counts++;
            pthread_mutex_unlock(&file_mutex);
            
            //printf("pid=%04d producet %d \n", pthread_self()%10000, i_in);
            fprintf(fp_out, "pid=%04d producet %d \n", pthread_self()%10000, i_in);
            usleep(1000);
        }
        pthread_mutex_unlock(&empty_mutex);
        //usleep(10000);
        if(i_in>MAX_NUMBER || exit_flag) break;
    }
    printf("producer %04d exited!\n", pthread_self()%10000);
    fprintf(fp_out, "producer %04d exited!\n", pthread_self()%10000);
    pthread_exit("produce over!");
}

//消费者线程
int consumer()
{
    int i;
    while(1)
    {
        pthread_mutex_lock(&full_mutex);
        
        while(buff_counts>0)
        {
            if(exit_flag_consumer)  break;
        
            pthread_mutex_lock(&file_mutex);
            i = get_one(buff);
            if(i<0)
            {
                printf("get_one failed!\n");
                pthread_mutex_unlock(&file_mutex);
                continue;
            }
            fprintf(fp, "buff_counts = %d //pid=%04d consume %d\n", buff_counts, pthread_self()%10000,i);
            if(i==MAX_NUMBER)
            {
                exit_flag_consumer = 1;
            }
            printf("pid=%04d consume %d\n", pthread_self()%10000,i);
            buff_counts--;
            pthread_mutex_unlock(&file_mutex); 
            
            if(exit_flag_consumer)
            {
                exit_flag = 1;
                break;
            }
            //usleep(1000);
//this sentence will make the get_one(buff) failed in the old thread
//问题出现在这里，如果这里用usleep，这一个消费者线程继续读取的缓冲区buff会失败（当缓冲区多余2个以上数据时）
//若不使用usleep，其他消费者线程获取缓冲区锁，不会出现读取失败的问题。
        }
        pthread_mutex_unlock(&full_mutex);
        if(i==MAX_NUMBER || exit_flag) break;
        usleep(1000);
    }
    printf("consumer %04d exited!\n", pthread_self()%10000);
    pthread_exit("consume over!");
}

int main(int argc, int argv[])
{
    pthread_t consumer_queue[MAX_CONSUMERS], producer_queue[MAX_PRODUCERS];
    int i,result;
    char temp[10];
    void *message;

    memset((void *)buff,0,sizeof(buff));
    fp = fopen("./123.txt", "wr+");
    fp_in = fopen("./in.txt", "w+");
    fp_out = fopen("./out.txt", "w+r");
    if(!fp)
    {
        perror("fopen failed!");
        exit(1);
    }
    result = pthread_mutex_init(&full_mutex, NULL);
    if(result)
    {
        perror("pthread_mutex_init failed!");
        exit(1);
    }
    
    result = pthread_mutex_init(&empty_mutex, NULL);
    if(result)
    {
        perror("pthread_mutex_init failed!");
        exit(1);
    }
    
    result = pthread_mutex_init(&file_mutex, NULL);
    if(result)
    {
        perror("pthread_mutex_init failed!");
        exit(1);
    }
    
//消费线程
    for(i = 0; i<MAX_CONSUMERS; i++)
    {
        result = pthread_create(&consumer_queue[i], NULL, (void *)consumer, NULL);
        if(result)
        {
            perror("pthread_create failed!");
            exit(1);
        }
    }
//生产线程
    for(i = 0; i<MAX_PRODUCERS; i++)
    {
        result = pthread_create(&producer_queue[i], NULL, (void *)producer, NULL);
        if(result)
        {
            perror("pthread_create failed!");
            exit(1);
        }
    }
    for(i = MAX_PRODUCERS-1; i>=0; i--)
    {
        pthread_join(producer_queue[i], &message);
        printf("return message is: %s\n", (char*)message);
    }
    sleep(1);
    fclose(fp);
    exit(0);
    
}