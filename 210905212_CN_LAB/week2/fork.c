#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(void){
	pid_t pid = fork();

	if(pid == 0){
		printf("child => PPID: %d PID: %d\n",getppid(),getpid());
		exit(EXIT_SUCCESS);

	}
	else if(pid > 0){
		printf("parent => pid: %d\n",getpid());
		printf("waiting for child to finish. \n");
		wait(NULL);
		printf("child process finished\n");
	}
	else{
		printf("Unable to create child process.\n");
	}

	return EXIT_SUCCESS;
}