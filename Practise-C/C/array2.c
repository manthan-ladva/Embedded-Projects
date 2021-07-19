#include<stdio.h>
#include<conio.h>

void main()
{
    int a[10];
    int i,n;
    float avg, sum=0;

    printf("Give the value of n : ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("Give Numbers : ");
        scanf("%d",&a[i]);

        sum = sum + a[i];
    }
    avg = sum/n;

    printf("-------------------------\n");
    printf("Array elements are : ");

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n\nSum : %f\nAvg : %f\n", sum, avg);
}
