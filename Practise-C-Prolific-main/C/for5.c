#include<stdio.h>

void main()
{
    int i,j,k,n;

    printf("Give the value of N : ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf(" ",j);
        }
        for(k=n;k>0;k--)
        {
            printf("*",k);
        }
        printf("\n");
    }
}
