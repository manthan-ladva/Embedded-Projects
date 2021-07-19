#include<stdio.h>
#include<conio.h>

void main()
{
    int a[10];
    int i,j,n,temp;

    printf("Give the value of n : ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("Give Numbers : ");
        scanf("%d",&a[i]);
    }

    printf("\nArray elements are : ");

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if (a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\n\nAscending Order Are : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n\nDescending Order Are : ");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
