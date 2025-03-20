#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    // io对象不能拷贝和赋值
    ofstream out1, out2;
    out1 = out2                   // 错误：不能拷贝
        ofstream print(ofstream); // 错误：传递参数的时候默认进行拷贝
    out2 = print(out2);           // 错误：不能拷贝流对象

    ifstr in(ifile);
    ofstream out;
    out.open(ifile + ".copy");
    if (out)              // 检测是否打开成功
                          // 操作
        in.close();       // 关闭文件
    in.open(ifile + "2"); // 打开另一个文件

    // 条件状态	参考表8.2

    // 自动构造和析构
    for (auto p = argv + 1; p != argv + argc; ++p)
    {
        ifstream input(*p);
        if (input)
        {
            process(input);
        }
        else
            cerr << "couldn't open: " + string(*p);
    }
    return 0;
}
