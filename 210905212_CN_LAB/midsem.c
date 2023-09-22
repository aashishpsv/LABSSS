//question is client that sends 2 structures and recives respone from server

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(){
	int len,ret,sockfd,n=1;
	char put[25],buf[256];
	struct sockaddr_in addr;

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1)
        {
		perror("sock not created");
		exit(0);
	}
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr=inet_addr("172.16.59.12");
	addr.sin_port=htons(7777);

	len = sizeof(addr);

	ret = connect(sockfd,(struct sockaddr*)&addr,len);
	if(ret==-1){perror("error");
	            exit(0);}

	printf("enter name:");
	gets(put);
	printf("sent to server \n");

	write(sockfd,put,sizeof(put));
    
    printf("recived from server:\n");
	while(n){
		//printf("recived from server:\n");
		n = read(sockfd,buf,sizeof(buf));
		puts(buf);
	} 
	
	close(sockfd);
	return 0;
}
