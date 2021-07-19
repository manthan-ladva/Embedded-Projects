#include<stdio.h>
#include<conio.h>

void main()
{
    char c1,c2,c3;

    printf("Enter first character : \n");
    c1 = getch();

    printf("\nEnter second character : \n");
    c2 = getche();

    printf("\nEnter third character : \n");
    c3 = getchar();

    printf("\nThe 1st value is : %c , 2nd value is : %c & 3rd value is %c", c1,c2,c3);
}


/*getchar() getch() getche() putchar()*/
