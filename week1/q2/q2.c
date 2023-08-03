#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *f1,*f2;
    char filename[100],c;
	printf("enter src name:\n");
	scanf("%s",filename);
	f1 = fopen(filename,"r");
    printf("enter dest name:\n");
    scanf("%s",filename);
    f2 = fopen(filename,"w+");

    fseek(f1,0,SEEK_END);
    int pos= ftell(f1) - 1;
    //fseek(f1,0,SEEK_SET);
    printf("pos: %d",pos);
    int i=1;
    while(i<=pos){
        fseek(f1,-i,SEEK_END);
        c = fgetc(f1);
        fputc(c,f2);
        i++;

    }
}
