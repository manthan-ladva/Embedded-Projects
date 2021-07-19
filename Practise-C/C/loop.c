#include<stdio.h>
#include<conio.h>

int main()
{
    int i,j,k,n,l;

    printf("Give the number: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            printf(" ",j);
        }
        for(k=1;k<=i;k++)
        {
            printf("%d",k);
        }

        for(l=k-2;l>=1;l--)
        {
            printf("%d",l);
        }
        printf("\n");
    }
}
