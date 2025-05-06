#include "Str_Blob.h"
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
}

void t_vector()
{
    vector<string> v1;
    {
        vector<string> v2 = {"a", "an", "the"};
        v1 = v2;
    }
    // 离开作用域后，v2被销毁其中元素也被销毁，但是v1仍然存在三个元素
}

void t_Blob()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2; // b1和b2元素共享
    }
    // 离开作用域后，b2被销毁，但是b1仍然存在，因此原来的三个元素没有被销毁
}