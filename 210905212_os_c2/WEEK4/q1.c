#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(){
	char filename[100];
	struct stat fileStat;

	printf("enter file name");
	scanf("%s",filename);

	if(stat(filename,&fileStat) == -1){
		printf("no file or error");
		return 0;
	}

	printf("inode no:%d\n",fileStat.st_ino);
	return 0;

}