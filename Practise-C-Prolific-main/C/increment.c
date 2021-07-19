#include<stdio.h>

void main()
{
    int a,b,c,d;
    a = 10;

    b = a++;    //a = 11, b = 10
    b--;        //a = 11, b = 9
    c = --b;    //a = 11, b = 8, c = 8
    d = c++;    //a = 11, b = 8, c = 9, d = 8
    ++c;        //a = 11, b = 8, c = 10, d = 8
    --d;        //a = 11, b = 8, c = 10, d = 7
    ++a;        //a = 12, b = 8, c = 10, d = 7
    b++;        //a = 12, b = 9, c = 10, d = 7

    printf("A : %d\n", a);
    printf("B : %d\n", b);
    printf("C : %d\n", c);
    printf("D : %d\n", d);
}
