#include<stdio.h>

int main()
{
    char c;
    printf("Give the value of C : ");
    c = getchar();

    printf("The value of C : ");
    putchar(c);

    printf("\nNew Value of C : ");
    putchar(c-32);
}
