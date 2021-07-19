#include<stdio.h>
#include<string.h>

void main()
{
    char data[] = "Hi I am Manthan.I am an Embedded Engineer.I am writing, cause of you.";
    int length,i;

    length = strlen(data);

    for(i=0;i<length;i++)
    {
        printf("%c", data[i]);
        if(data[i]== '.')// || data[i]==',')
        {
            printf("\n");
        }
    }
}
