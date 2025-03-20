#include <iostream>
using namespace std;
int main(void)
{
	int iVal = 1024;
	int &refVal = iVal;
	cout << refVal << endl;

	refVal = 2;
	cout << iVal << endl;

	int ii = refVal;
	cout << ii << endl;

	int &refVal3 = refVal;
	refVal3 = refVal;
	cout << iVal << endl;

}
