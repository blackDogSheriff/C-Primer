#include <iostream>
#include <fstream>
/*
文件模式：
    in		只读
    out		写
    app		append，每次写操作前定位到文件末尾
    ate		打开文件后立即定位到文件末尾
    trunc	截断文件
    binary	以二进制的方式进行IO
*/
using namespace std;

int
main(void)
{
    ofstream out("file1");
    ofstream out2("file1", ofstream::out); // 默认truncate
    ofstream out3("file1", ofstream::out | ofstream::trunc);

    ofstream app("file1", ofstream::app);
    ofstream app2("file1", ofstream::out | ofstream::app);

    // 每次调用open时都会确定文件模式
    ofstream out;
    out.open("scratchpad");
    out.close() out.open("precious", ofstream::app);
    out.close();
}
