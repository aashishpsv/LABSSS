#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fa,*fb;
	char ca,cb;

	fa = fopen("q2_sample.c","r");
	if(fa==NULL){
		printf("cant open");
		fclose(fa);
		exit(0);
	}

	fb= fopen("q2_out.c","w+");

	ca = getc(fa);

	while(ca!=EOF){
		if(ca == '#'){
			while(ca != '>'||ca=='\n'){
				ca=getc(fa);
			}
        }
		else putc(ca,fb);
		ca = getc(fa);
	}

	fclose(fa);
	fclose(fb);
	return 0;
}