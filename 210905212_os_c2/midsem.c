#include<stdio.h>
#include<pthread.h>

int reverse(int x){
	int rev =0;int rem=0;
	int i=1;

	while(x>0){
		rem = x%10;
		rev = rev*i +rem;
		i=i*10;
		x = x/10;
	}
}

void *prime(void *param){
	int x = (int)param;
	int y;

	for(int i=2;i*i<x;i++){
		if(x%i==0)
		{
			 y=reverse(x);
		}
	}
	return (void*) y;
}

void *zeros(void *param){
	int no = (int)param;
	no =0;
	return (void*) no;

}

int main(){
	int m,n;

	printf("enter dimensions");
	scanf("%d %d",&m,&n);
	int mat[m][n];
    printf("enter numbers");
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		scanf("%d",&mat[i][j]);
    	}
    }
	pthread_t thr1[m],thr2[m];

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
		{pthread_create(&thr1[i],0,&prime,(void*)mat[i][j]);}
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
		{pthread_join(thr1[i],(void**)mat[i][j]);}
	}

	for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		printf("%d \t",mat[i][j]);
    	}
    	printf("\n");
    }

	 for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
	 	{
	      if(i==1 && j == 1|| i==1 && j==m || i==m && j ==1||i==m && j==n) {
	 			pthread_create(&thr2[i],0,&zeros,(void*)mat[m][n]);
	 	}
	 }
	}

	for(int i=1;i<=m;i++){
	 	for(int j=1;j<=n;j++)
	 	{pthread_join(thr2[i],(void**)mat[m][n]);}
	 }

	 for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		printf("%d \t",mat[i][j]);
    	}
    	printf("\n");
    }

}
