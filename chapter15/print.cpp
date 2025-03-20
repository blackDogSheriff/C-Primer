#include <iostream>
using namespace std;
class base {
public:
	base(string szNm) : basename(szNm) {} 
	string name() { return basename; }
	virtual void print(ostream &os) { os << basename; }	
private:
	string basename;
};

class derived : public base {
public:
	derived(string szName, int iVal) : base(szName), mem(iVal) { }
	void print(ostream &os) 
	{ 
		base::print(os); 
		os << " " << mem << endl; }
private:
	int mem;
};

int main(void)
{
	derived de("C++ Primer", 3);
	de.print(cout);
	return 0;
}
