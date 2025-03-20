#include <iostream>
using namespace std;
int main(void)
{
#if 0
	list<string> authors = {"Milton", "Shakespeare", "Austen"};
	vector<const char *> articles = {"a", "an", "the"};

	//拷贝容器需要容器类型匹配
	list<string> list2(authors);
	deque<string> authList(authors);	//错误，容器类型不匹配
	vector<string> words(articles);		//错误，容器类型必须匹配

	//拷贝范围内元素不需要容器类型匹配，但是元素类型匹配或者可转换
	forword_list<string> words(articles.begin(), articles.end());

	//定义数组的时候除了可以指定元素类型，还要制定容器大小
	array<int, 42>
	array<string, 10>

	array<int, 10>::size_type i;

	array<int, 10> a1 = {0,1,2,3,4,5,6,7,8,9};
	array<int, 10> a2 = {0};
	a1 = a2;	//可以，左右两边运算对象类型相同
	a2 = {0};	//错误，不可以将初始化列表赋值给数组

	//可以直接拷贝
	int digs[10] = {0,1,2,3,4,5,6,7,8,9};
	int cpy[10] = digs;
	array<int, 10> a1 = {0,1,2,3,4,5,6,7,8,9};
	array<int, 10> copy = digits;

	//swap:交换C1和C2的元素	类型相同
	swap(a1, a2);	//理解为指针交换
	a1.swap(a2);

	vector<string> svec1(10);
	vector<string> svec2(24);
	//除了array以外，swap不对任何元素进行拷贝、
	//删除、或者插入操作，因此可以保证在常数时间内完成
	//交换数组会真正的交换数组里面的元素, 因此交换时间和元素数目成正比
	//交换数组不会改变指针、引用、迭代器
	swap(svec1, svec2);	

	//assign:元素替换
	//assign只有顺序容器和数组可以使用, 左边和右边的类型必须相同, 但是不可以拷贝数组
	seq.assign(b, e);
	seq.assign(il);
	seq.assign(n, t);

	list<string> names;
	vector<const char *> oldstyle;
	names = oldstyle;	//错误，容器类型不匹配
	names.assign(oldstyle.cbegin(), oldstyle.cend());

	//容器大小操作	
	//size()	容器中元素数目
	//empty()	返回容器是否为空
	//max_size()	最大元素数量
	
	//容器相同，元素相同	
	//只有定义了相应的比较运算符时，我们才可以使用关系元算符来比较两个容器

	//容器访问:
	s.front();
	s.back();
	s.at(0);	//越界会报错
	s[10];

	//删除元素
	c.pop_back();	//forword_list不支持
	c.pop_front();	//vector, string不支持
	//指向删除元素后的迭代器
	c.erase(p);		//删除迭代器p指向的元素
	c.erase(b, e);	//删除迭代器b, e之间的元素
	c.clear();		//删除c中所有的元素
#endif

    return 0;
}
