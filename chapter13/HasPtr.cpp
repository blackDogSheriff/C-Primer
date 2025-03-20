#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr {
	friend void swap(HasPtr &, HasPtr &);
public:
	HasPtr(const string &s = string()):
			ps(new string (s)), i(0) { }
	HasPtr(const HasPtr &p): 
			ps(new string(*p.ps)), i(p.i) { }
	HasPtr& operator=(const HasPtr &);
	HasPtr& operator=(const string &);
	string& operator*();
	bool operator<(const HasPtr &) const;
	~HasPtr();
private:
	string *ps;
	int i;
};

HasPtr::~HasPtr() 
{
	delete ps;
}


inline HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	auto newps = new string(*rhs.ps);
	delete ps;
	ps = newps;
	i = rhs.i;
	return *this;
}

HasPtr& HasPtr::operator=(const string &rhs)
{
	*ps = rhs;
	return *this;
}

string &HasPtr::operator*()
{
	return *ps;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using swap;
	cout << "交换" << *lhs.ps << "和" << *rhs.ps << endl;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

bool HasPtr::operator<(const HasPtr &rhs) const 
{
	return *ps < *rhs.ps;
}
//拷贝交换技术
HasPtr& HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);	//rhs现在指向本对象曾经使用的内存
	return *this;		//rhs被销毁，从而delete了rhs中的指针，析构函数delete了rhs
}

bool HasPtr::operator<(const HasPtr &rhs) const 
{
	return *ps < *rhs.ps;
}

int main(void)
{
#if 0
	HasPtr h("hi mom!");
	HasPtr h2 (h);
	HasPtr h3 = h;
	h2 = "hi dad!";
	h3 = "hi son!";

	swap(h2, h3);

	cout << "h: " << *h << endl;
	cout << "h2: " << *h2 << endl;
	cout << "h3: " << *h2 << endl;
#endif 
	vector<HasPtr> vh;
	int n = atoi(argv[1]);
	for (int i = 0; i < n; i++)
		vh.push_back(to_string(n-i));
	for (auto p : vh)
		cout << *p << " ";
	cout << endl;
	sort(vh.begin(), vh.end());
	for (auto p : vh)
		cout << *p << " ";
	cout << endl;
	return 0;
}
