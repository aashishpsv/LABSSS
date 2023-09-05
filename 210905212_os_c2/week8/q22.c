#include <stdio.h>
#include <pthread.h>

void* add(void *param){
    int no = (int)param;
    int x;
    int sum=0;
    for(int i=0;i<no;i++){
        printf("enter no %d :",(i+1));
        scanf("%d",&x);
        if(x>0){
            sum = sum + x;
        }
    }
    return (void *)sum;
}

int main(){
    int x;
    printf("Enter the number of numbers:");
    scanf("%d", &x);
    int sum;
    pthread_t thread;
    pthread_create(&thread, 0, add, (void*)x);
    pthread_join(thread, (void**)&sum);
    printf("the sum is : %d\n",sum);
   
    return 0;
}