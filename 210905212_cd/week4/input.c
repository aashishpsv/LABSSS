



void printArray(int array[] , int size){
	for(int i=0;i<size;++i){
		printf("%d",arr[i]);
	}
	printf("\n");
}
//print Array

int main(){
	int data[] = (2,45,0,11,9);

	//find the arrays length
	int size = sizeofdata(data) / sizeof(data[0]);

	printf("entered array   :/n");
	printArray(data,size);

}