#include<stdio.h>
#include<conio.h>

main()
{
//    int a[10];
    char b[] = {'Manthan', 'Ladva'};
    int i, count=0;

    printf("Give the string\n");

    for(i=0; b[i]!=NULL; i++)
    {
        count++;
    }
//
    printf("Length of string = %d\n", count);
}
