#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){
	pid_t pid;
	int n;
	char *message;
	pid = fork();
	switch(pid){
		case -1:
					perror("fork failed");
					exit(1);
		case 0:
					message = "This is the child";
					n = 4;
					break;
		default:
					message = "This is the parent";
					n = 6;
					break;
	}
	for(; n > 0; n--) {
			puts(message);
			sleep(1);
			}
	exit(0);
}