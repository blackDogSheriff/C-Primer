#include <iostream>
using namespace std;
struct NoCopy
{
	NoCopy() = default;
	NoCopy(const NoCopy &) = delete;			// 阻止拷贝
	NoCopy &operator=(const NoCopy &) = delete; // 阻止赋值
	// 不可以删除析构函数
	~NoCopy() = delete; // 错误
};
int main(void)
{
	// 不可以定义变量或成员，但是可以分配这种类型的对象，且不能释放
	NoCopy nd;				  // 错误，NoDtor析构函数被删除了
	NoCopy *p = new NoCopy(); // 正确，但是不可以销毁NoCopy对象
	return 0;
}
