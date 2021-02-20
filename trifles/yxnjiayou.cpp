#include<iostream> 
using namespace std;
int main()
{int m,n,i,j;
int max=0,min=100,score[100];
double avg=0,sum=0;
cout<<"��������ί������ѡ������";
cin>>n>>m;
for(j=1;j<=m;j++)
{cout<<j<<"��ѡ��: ";
for(i=1;i<=n;i++) 
{
cin>>score[i];
sum=sum+score[i];
if(score[i]>max) 
{max=score[i];}
if(score[i]<min) 
{min=score[i];}
avg=(sum-max-min)/(n-2);
avg=avg*0.1*10;
}
cout<<"���÷�: "<<avg<<endl;
}
return 0;
}
