#include<stdio.h>
#include<conio.h>

void main()
{
    int a[10];
    int i, n;
    int max, min;

    printf("Give the value of n : ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("Give Numbers : ");
        scanf("%d",&a[i]);
    }

    max = a[0];
    min = a[0];

    for(i=0;i<n;i++)
    {
        if (max<a[i])
        {
            max = a[i];
        }
        if (min>a[i])
        {
            min = a[i];
        }
    }

    printf("-------------------------\n");
    printf("Array elements are : ");

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n\nLargest : %d\tSmallest : %d", max,min);
}
