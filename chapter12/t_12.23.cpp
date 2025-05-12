#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
    const char *p1 = "hello";
    const char *p2 = "world";

    char *r = new char[strlen(p1) + strlen(p2) + 1];
    strcpy(r, p1);
    strcpy(r, p2);

    string s1 = "hello";
    string s2 = "world";
    strcpy(r, (s1 + s2).c_str());

    delete[] r;
    return 0;
}