#include <stdio.h>
#include <string.h>

char passwordone[] = "5100702D979B";
unsigned char id_password[][13] = {"510060156B4F", "51005ECF35F5", "5100702D979B"};

int compare()
{

    int i;
    for(i=0;i<3;i++)
    {
        printf("%s\t%s\n",passwordone, id_password[i]);
        if(strcmp(passwordone, id_password[i])==0)
        {
            return 0;
        }
    }
}

int main()
{
//    if(compare(passwordone)==0)
//    {
//        printf("Yes");
//    }
//    else
//    {
//        printf("No");
//    }
    int i = sizeof(id_password)/sizeof(id_password[0]);
    printf("%d", i);
}
