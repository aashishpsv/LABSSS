#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>



struct my_msg_st{
	long int my_msg_type;
	char some_txt[BUFSIZ];
};

int main (){
	int running =1;
	int msgid;
	struct my_msg_st some_data;
	long int msg_to_recieve = 0;


	msgid = msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid == -1){
		fprintf(stderr,"msgget failed with err:%d\n",errno);
		exit(EXIT_FAILURE);
	}
	while(running){
		if(msgrcv(msgid,(void*)&some_data,BUFSIZ,msg_to_recieve,0)==-1){
			fprintf(stderr,"mssgget failed with erroe.%d\n",errno);
			exit(EXIT_FAILURE);
		}
		int length=strlen(some_data.some_txt);
	    int flag=1;
	    length=length-1;
	    for(int i=0;i<length/2;i++)
	    {
		if(some_data.some_txt[i]!=some_data.some_txt[length-i-1])
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
		printf("palindrome");
	else
		printf("not a palindrome");
	printf("\nNumber recieved: %s",some_data.some_txt);
		if(strncmp(some_data.some_txt,"end",3)==0){
			running = 0;
		}
	}
	if(msgctl(msgid,IPC_RMID,0)==-1){
		fprintf(stderr,"msgctl(IPC_RMID) FAILED\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
