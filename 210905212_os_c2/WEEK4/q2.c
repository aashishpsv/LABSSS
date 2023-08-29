#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>

int main(){
	char filename[100];
	struct stat fileStat;

	printf("enter file name");
	scanf("%s",filename);

	if(stat(filename,&fileStat) == -1){
		printf("no file or error");
		return 0;
	}
    printf("the stat structure:\n");
	printf("device node:%ld\n",fileStat.st_dev);
	printf("inode no:%ld\n",fileStat.st_ino);
	printf("mode:%ld\n",fileStat.st_mode);
	printf("nlink:%ld\n",fileStat.st_nlink);
	printf("user id:%ld\n",fileStat.st_uid);
	printf("group id:%ld\n",fileStat.st_gid);
	printf("device container:%ld\n",fileStat.st_rdev);
	printf("size:%ld\n",fileStat.st_size);
	printf("blk size:%ld\n",fileStat.st_blksize);
	printf("no of blocks:%ld\n",fileStat.st_blocks);
    printf("Last access time: %s\n", ctime(&fileStat.st_mtime));
	printf("last modify time:%s\n",ctime(&fileStat.st_mtime));
	printf("last change time:%s\n",ctime(&fileStat.st_ctime));


	return 0;
}

