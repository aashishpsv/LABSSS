#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *f1,*f2,*f3;
    char filename[100],c1,c2;
    int flag=0;
	printf("enter src name:\n");
	scanf("%s",filename);
	f1 = fopen(filename,"r");
    printf("enter src name:\n");
    scanf("%s",filename);
    f2 = fopen(filename,"r");
    printf("enter dest name:\n");
    scanf("%s",filename);
    f3 = fopen(filename,"w+");
    c1=fgetc(f1);
    c2=fgetc(f2);
    while(c1!=EOF && c2!=EOF)
    {
        if(flag==0){
          if(c1=='\n') 
              flag=1;
            fputc(c1,f3);
            c1=fgetc(f1);
        
        }
        if(flag==1){
       
            if(c2=='\n') 
              flag=0;
            fputc(c2,f3);
            c2=fgetc(f2);
        }
      

    }
            while(c1!=EOF)
        {
            fputc(c1,f3);
            c1=fgetc(f1);
        }

        while(c2!=EOF)
        {
            fputc(c2,f3);
            c2=fgetc(f2);
        }

    }

    




    

