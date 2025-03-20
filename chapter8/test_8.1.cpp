#include <iostream>
#include <stdexcept>
using namespace std;
istream &f(istream &in)
{
    int v;
    while (in >> v, !in.eof())
    {
        if (in.bad()) // badbit表示系统级错误，比如不可恢复的读写错误，badbit被置位，流就无法在使用
            throw runtime_error("IO流错误");
        if (in.fail())
        {
            cerr << "数据错误，请重试：" << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main(void)
{
    cout << "请输入一些整数，按Ctrl+Z结束" << endl;
    f(cin);
    return 0;
}

/*

    //文件结束之后eofbit和failbit被置位

    状态：
        1. iostate
        2. badbit	//用来指出流已经崩溃，无法恢复错误
        3. failbit	//用来指出一个IO操作已经失败了，可恢复错误
        4. eofbit	//用来指出流到达了文件结束
        5. goodbit	//用来指出流未处于错误状态, 此值保证为0
    处理函数：
        1. s.eof()		//如果eofbit置位，则返回true
        2. s.fail()		//如果failbit或者badbit置于位，则返回true
        3. s.bad()		//如果badbit置位，则返回true
        4. s.good()		//如果流处于有效状态，则返回true
        5. s.clear()	//将s中所有状态复位，将流的状态设置为有效，返回void
        6. s.clear(flags)
   //将flag的条件状态复位，flag的类型为iostream，返回void
        7. s.setstate(flags)
   //将flag的条件状态复位，flag的类型为iostream，返回void
        8. s.rdstate()			//返回s的当前条件状态，返回值类型为iostate
*/
