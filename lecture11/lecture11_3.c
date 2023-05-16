#include <stdio.h>
#include<string.h>
int strPrint(const char* string)
{
    char *a;
    a = (char* )string;
    printf("%s",a);
    return 0;
}
int main()
{
    char a[30];

    int i = 0;
    while (i<30)
    {
        a[i] = 'o'; 
        i=i+1;
    }
    
    char temp[20] = "Fuck you";
    i = 0;
     while (i<20)
    {
        
        if(temp[i]=='\0')
        {
            i=20;
        }
        else
        {
        a[i+5] = temp[i]; 
        i=i+1;
        }
    }

    printf("%s",a);

    strPrint("Lunch Eat!!!");

    return 0;
}