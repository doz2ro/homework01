#include <stdio.h>
int add (int a, int b)
{
    return a+b;
}
int initVariable(int* i)
{
    *i = 0;

    return 0;
}
int main()
{
    int a = 10;
    int b = 7;
    initVariable(&b);
    printf("%d",add(a,b));
    return 0;
}