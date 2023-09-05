#include <stdio.h>
#include <pthread.h>
#include <stddef.h>


int arrsize;

int isEven(int num) {
    if (num % 2 == 0) { return 1; }
    return 0;
}

void* sumEven(void* param) {
    int* array = (int*)param;
    int sum = 0;
    for (int i = 0; i < arrsize; i++) {
        if (isEven(array[i])) {
            sum += array[i];
        }
    }
    printf("Sum of even numbers: %d\n", sum);
}

void* sumOdd(void* param) {
    int* array = (int*)param;
    int sum = 0;
    for (int i = 0; i < arrsize; i++) {
        if (!isEven(array[i])) {
            sum += array[i];
        }
    }
    printf("Sum of odd numbers: %d\n", sum);
}

int main() { 
    printf("enter arr size:");
    scanf("%d",&arrsize);
    int array[arrsize]; 
    printf("Enter %d numbers:\n",arrsize); 
    for (int i = 0; i < arrsize; i++) { 
        scanf("%d", &array[i]); 
    } 
    pthread_t thread1, thread2; 
    pthread_create(&thread1, NULL, sumEven, (void*)array); 
    pthread_create(&thread2, NULL, sumOdd, (void*)array); 
    pthread_join(thread1, NULL); 
    pthread_join(thread2, NULL); 
    return 0; 
}