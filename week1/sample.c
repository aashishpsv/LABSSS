#include<stdio.h>
#include<stdlib.h>

int main(){
		FILE *f1,*f2;
		char filename[100],c;
		printf("enter the file name");
		scanf("%s",filename);
		f1 = fopen(filename,"r");
		if(f1==NULL){
			printf("cant");
			exit(0);
		}
		printf("enter dest name:");
		scanf("%s",filename);
		f2=fopen(filename,"w+");
		c=fgetc(f1);
		while(c!=EOF){
			fputc(c,f2);
			c=fgetc(f1);
		}
		fclose(f1);
		fclose(f2);
		return 0;
}