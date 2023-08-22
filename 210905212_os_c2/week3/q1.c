#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	pid_t pid1;
	int status;
	pid1 = fork();
	if(pid1 == -1){
		printf("error. child = absent");
	}
	else if(pid1 == 0){
		printf("child start\n");
		for(int i=0;i<3;i++){
			printf("hi %d\n",i);
		}
		printf("child done\n");
		exit(0);
	}
	else{
		printf("parent started.\n");
		wait(&status);
		printf("parent ended\n");
	}
}