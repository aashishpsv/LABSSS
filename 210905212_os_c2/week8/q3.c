#include <stdio.h>
#include <pthread.h>

int isPrime(int num) {
    if (num <= 1) { return 0;}
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void* Prime(void* param) {
    int start = *((int*)param);
    int end = *((int*)param + 1);
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    int start, end;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);
    pthread_t thread;
    int params[2] = {start, end};
    pthread_create(&thread, 0, Prime, (void*)&params);
    pthread_join(thread, 0);
    return 0;
}