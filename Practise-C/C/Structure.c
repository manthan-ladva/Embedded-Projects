#include<stdio.h>
#include<conio.h>

void main()
{
    struct student
    {
         int rollno;
         int age;
         char sex[10];
         char name[20];
         char address[30];
         char city[20];
    } s1;

    printf("Give Roll number : "); /*Roll Number*/
    scanf("%d", &s1.rollno);

    printf("Give Age : "); /*Age*/
    scanf("%d", &s1.age);

    printf("Give Name : "); /*Name*/
    scanf("%s",&s1.name);

    printf("Give City : "); /*City*/
    scanf("%s",&s1.city);

    printf("Give Address : "); /*Address*/
    scanf("%s",&s1.address);

    printf("Give Sex : "); /*Sex*/
    scanf("%s", &s1.sex);

    printf("\n\nRoll Number = %d\nName = %s\nAddress = %s\n", s1.rollno, s1.name, s1.address);
    printf("City = %s\nSex = %s\nAge = %d", s1.city, s1.sex, s1.age);
}
