#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	pid_t pid,pid1;
	int status;
	pid = fork();
	switch(pid){
		case -1: printf("no child\n");
				 exit(-1);
		case 0: printf("child start\n");
			    printf("PID: %d,Parent PID: %d,Child PID: %d\n", getpid(), getppid(), pid);
			    printf("child done\n");
				exit(0);
		default: wait(&status);
				 printf("parent start\n");
				 printf("Child Status : %d,PID: %d,Parent PID: %d,Child PID: %d\n", status, getpid(), getppid(), pid);
				 printf("parent done\n");
	}
	return 0;
}