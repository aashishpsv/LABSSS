#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	pid_t pid;
	pid = fork();
	if(pid<0){
		fprintf(stderr,"fork failed");
		exit(-1);
	}
	else if(pid == 0){
		execlp("./q1", "q1", NULL);
	}
	else{
		wait(NULL);
		printf("child of q2 done.");
		exit(0);
	}
}