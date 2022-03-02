#include<pthread.h>
#include<stdio.h>
int len,len1;
void* thread1(void *u) {
int *ptr=(int *) u;
int sum=0;
for(int i=0;i<2;i++) {
sum=sum+ptr[i];

}
printf("The sum is %d\n",sum);
}
void* thread2(void *u) {
int *ptr=(int *) u;
int sum=0;
for(int i=2;i<4;i++) {
sum=sum+ptr[i];
}
printf("The sum is %d\n",sum);
}
void* sumArray(void *u) {
int *ptr=(int *) u;
int sum=0;
for(int i=0;i<len1;i++) {
sum=sum+ptr[i];
}
printf("The sum is %d\n",sum);
}
int main() {

int N,t,i,a[N];
printf("N value: \n");
scanf("%d", &N);
len1=N;
printf("Enter t:\n");
scanf("%d",&t);
printf("Your array values: \n");	
for(i=0;i<N;i++)
{
scanf("%d",&a[i]);
}
len=N/t;

pthread_t tid;
pthread_t tid1;
pthread_t tid2;



pthread_create(&tid1,NULL,&thread1,&a);
pthread_join(tid1,NULL);

pthread_create(&tid2,NULL,&thread2,&a);
pthread_join(tid2,NULL);

pthread_create(&tid,NULL,&sumArray,&a);
pthread_join(tid,NULL);



return 0;
}

