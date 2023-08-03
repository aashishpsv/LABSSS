#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *f1;
    char filename[100],c;
    int lines=1,characters=0;
	printf("enter src name:\n");
	scanf("%s",filename);
	f1 = fopen(filename,"r");
    c=fgetc(f1);
	while(c!=EOF)
	{

		if(c=='\n')
			lines++;
		characters++;
		c=fgetc(f1);
	}

	printf("lines are:%d",lines);
	printf("character are: %d",characters);
    return 0;
}