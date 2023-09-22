// test.cpp
#if 0
void foo(void) { }
void foo(int x) { }

/*
0000000000000000 T __Z3foov
0000000000000004 T __Z3fooi

*/
#endif

#if 0
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(int a) { cout << "Sample(int)" << endl; }
    Sample(int a, double b) { cout << "Sample(int, double)" << endl; }
};

int main()
{
    Sample s1; // Sample()
    Sample s2(10); // Sample(int)
    Sample s3(10, 3.14); // Sample(int, double)

    // Uniform Initialization
    Sample ss2 { 10 }; // Sample(int)
    Sample ss3 { 10, 3.14 }; // Sample(int, double)
}
#endif
