#include<stdalign.h>
#include<stdio.h>

int main(){
	FILE *fa,*fb;
	char ca,cb;

	fa = fopen("q2_sample.c","r");
	if(fa==NULL){
		printf("cant open");
		fclose(fa);
		exit(0);
	}

