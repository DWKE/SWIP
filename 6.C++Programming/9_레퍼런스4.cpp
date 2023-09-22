// 9_레퍼런스4.cpp
#include <iostream>
using namespace std;

class Color {
public:
    Color(int r, int g, int b)
    {
        cout << "Color(int, int, int)" << endl;
    }

    ~Color()
    {
        cout << "~Color()" << endl;
    }
};

// 1. 임시 객체는 rvalue 입니다.
// 2. 임시 객체를 만드는 방법
// 3. 임시 객체의 수명은 참조에 의해서,
//    참조 변수의 수명과 동일하게 유지됩니다.

// 4. rvalue를 참조하는 방법
//   1) const lvalue reference
//   2) C++11, rvalue reference

#if 0
int main()
{
    cout << "--------" << endl;
    // const Color& r = Color(10, 20, 30); // Color(int, int, int)
    Color&& r = Color(10, 20, 30); // Color(int, int, int)
    cout << "--------" << endl;
}
#endif

// C++11 이전에는 const reference를 이용해서,
// lvalue와 rvalue를 한번에 처리하였습니다.
void SetBackground(const Color& r)
{
    cout << "lvalue" << endl;
}

// C++11 이후에는 rvalue를 독립적으로 처리할 수 있는
// rvalue reference 개념이 도입되었습니다.
void SetBackground(Color&& c)
{
    cout << "rvalue" << endl;
}

int main()
{
    Color c { 10, 20, 30 };
    SetBackground(c);

    SetBackground(Color { 10, 20, 30 });
}
