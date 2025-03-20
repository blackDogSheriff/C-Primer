#include <iostream>
using namespace std;
int main(void)
{
	istream_iterator<Sales_item> item_iter(cin), eof;
	ostream_iterator<Sales_item> out_iter(cout, "\n");
	Sales_item sum = *item_iter++;
	while (iter_iter != eof) {
		if (item_iter->isbn() = sum.isbn())
			sum += *iter_iter++;
		else
		{
			out_iter = sum;
			sum = *item_iter++;
		}
	}
	out_iter = sum;
	return 0;
}
