#include <stdio.h>

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int(*b)[5] = &a; //指向数组的指针
    int *c = a;

    return 0;
}