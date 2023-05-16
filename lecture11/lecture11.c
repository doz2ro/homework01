#include <stdio.h>

int main()
{
    int a = 10;
    int *b;
    b = &a;
    *b = 15;
    printf("%d", a);

    return 0;
}