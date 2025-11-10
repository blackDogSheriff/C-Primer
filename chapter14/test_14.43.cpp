#include <iostream>
using namespace std;
bool dividedByAll(vector<int> &ivec, int dividend)
{
    return count_if(ivec.begin(), ivec.end(), bindlst(modulus<int>, dividend)) == 0;
}
int main(void)
{
    return 0;
}
