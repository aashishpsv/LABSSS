#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>

int main(){
	int len,result,sockfd,n=1;
	struct sockaddr_in address;
	char ch[256],buf[256];

	sockfd=socket(AF_INET,SOCK_STREAM,0);

	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("172.16.48.80");
	address.sin_port=htons(10200);
	len = sizeof(address);

	result = connect(sockfd,(struct sockaddr*)&address,len);
	if(result==-1){
		perror("client error");
		exit(1);
	}

	   printf("\nENTER STRING\t");
     gets(ch);
     ch[strlen(ch)]='\0';
     write(sockfd,ch,strlen(ch));
     printf("STRING SENT BACK FROM SERVER IS ..... ");
     while(n){
     n=read(sockfd,buf,sizeof(buf));
     puts(buf);
   }

   close(sockfd);
   close(address.sin_port);

  
}