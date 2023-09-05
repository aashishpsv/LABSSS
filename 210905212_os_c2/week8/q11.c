#include <stdio.h>
#include <pthread.h>

void* fibonacci(void *param){
    int no = (int)param;
    if(no == 0){return 0;}
    if(no == 1){return 1;}
    int fib[no];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= no; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return (void*)fib[no];
}

int main(){
    int x;
    printf("Enter the number of Fibonacci numbers required: ");
    scanf("%d", &x);
    pthread_t thread[x];
    int return_value[x];
    for(int i = 0; i < x; i++){
        pthread_create(&thread[i], 0, fibonacci, (void*)i);
    }
    for(int i = 0; i < x; i++){
        pthread_join(thread[i], (void**)&return_value[i]);
        printf("%d\n", return_value[i]);
    }

    return 0;
}