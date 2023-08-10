#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fa,*fb;
	int ca,cb;

	fa = fopen("q1_sample.c","r");
	if(fa==NULL){
		printf("cant open");
		fclose(fa);
		exit(0);
	}

	fb= fopen("q1_out.c","w+");

	ca = getc(fa);

	while(ca!=EOF){
		if(ca == ' '){
			putc(ca,fb);
			while(ca == ' '){
				ca=getc(fa);
			}

		}
		else{
			//while(ca!='\n'){
				putc(ca,fb);
				ca=getc(fa);
			//}
		}
	}
	return 0;
}