#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getmemory(char *p)
{
    //这里修改的是局部参数，对传递近来的参数没有影响
    p = (char *)malloc(100);
    strcpy(p, "hello world");
    printf("%s\n", p);
}
void func(const char *p)
{
    p = "jaksdl";
}

void func1(int a)
{
    a = 20;
}

void func2(char **p)
{
    *p = (char *)malloc(100);
    strcpy(*p, "hello world");
}

int main(void)
{
#if 0
	char *str = NULL;
	getmemory(str);
	printf("%s\n", str);
	free(str);

	const char *p = "123123";
	func(p);
	printf("%s\n", p);
	return 0;

	int a = 10;
	func1(a);
	printf("%d\n", a);
#endif
    char *p1 = NULL;
    char **p = &p1; //存放指针的
    func2(p);
    printf("%s\n", p1);
    return 0;
}
