#include <iostream>
using namespace std;
class HasPtr {
public:
	HasPtr(const string &s = string()): ps(new string(s)), i(0) { }
	HasPtr(const HasPtr	&s): ps(new string(*s.ps)), i(s.i) { } 
private:
	string *ps;
	int i;
};
int main(void)
{

	return 0;
}
