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