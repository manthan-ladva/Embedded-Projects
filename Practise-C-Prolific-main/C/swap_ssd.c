#include<stdio.h>

void swap(unsigned int *value1, unsigned int *value2, unsigned int *value3, unsigned int *value4){
	unsigned int temp;

	temp = *value1;
	*value1 = *value2;
	*value2 = *value3;
	*value3 = *value4;
	*value4 = temp;

	return;
}

void swapper(unsigned int a, unsigned int b, unsigned int c, unsigned int d){

	swap(&a, &b, &c, &d);

	printf("After Swap : %d %d %d %d", a, b, c, d);
	//swapper(a,b,c,d);
}

void main(){
	int i,j,k,l;
	i = 10;
	j = 20;
	k = 30;
	l = 40;

	printf("\nBefore Swap : %d %d %d %d\n", i, j, k, l);

	swap(&i, &j, &k, &l);

	printf("After Swap : %d %d %d %d", i, j, k, l);

}
