#include<stdio.h>
#include<string.h>

void main(void)
{
    char welcome[11] = "Welcome ";
    char number[][5] = {"1", "2", "3"};
	//int i = 49;
	//char d;
	//char ch = (char)i;
	//strncat(welcome, &ch, 1);
	strcat(welcome, number[2]);
	printf("%s", welcome);
}
