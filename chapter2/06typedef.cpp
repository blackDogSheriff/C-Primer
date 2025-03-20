#include <iostream>
using namespace std;

// 使用typedef
typedef double wages;
typedef wages base, *p;

// 使用别名声明 - 两者等价
using SI = int;
/************************************/

typedef char *pstring;

/*
cstr类型为，char *，cstr本身是一个常量指针
*/
const pstring cstr = 0;

/*
ps类型为指针，它的对象是指向char的常量指针；
*/
const pstring *ps = 0; //ps指向”指向char的常量指针；“
char c;

const char *a = &c;
char *b = &c;

//不能通过ps1修改c的值；
const char **ps1 = &a; //ps1指向“指向char常量的指针”
char *const *ps2 = &b; //ps2指向“指向char的常量指针”
char ** const ps3 = &b; //ps2是常量指针，指向“指向char的指针”

int main(void)
{
}