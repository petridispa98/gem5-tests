#include <stdio.h>
#include <stdlib.h>
#define size 5

int main(int argc, char *argv[]) {
	int  p[size];
	int i;
	printf("Array size is %i\n",size);
	int max=0;
	int min=100;
	int sum=0;
	for (i=0;i<size;i++){
		p[i]=i*i -2*i +10;
		printf(" \n elements %d :  %d " ,i+1,p[i]);
		sum=sum+p[i];
		if(p[i]>max)
		max=p[i];
		if(p[i]<min)
		min=p[i];

	}
	printf("\n max element : %d",max);
	printf("\n min element: %d",min);
	printf("\n mean: %d",sum/size);
	return 0;
}
