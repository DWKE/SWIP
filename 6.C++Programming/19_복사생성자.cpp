// 19_복사생성자.cpp
#include <iostream>
using namespace std;

// 1) 사용자가 생성자를 1개도 제공하지 않으면,
//    컴파일러는 아무일도 수행하지 않는 기본 생성자를 제공합니다.
// 2) 사용자가 생성자를 1개라도 제공하면,
//    컴파일러는 기본 생성자를 제공하지 않습니다.

// 3) 사용자가 자신과 동일한 타입을 인자로 전달받는 생성자(복사 생성자)를
//    제공하지 않는다면, 컴파일러는 멤버를 복사하는 복사 생성자를
//    제공합니다.
#if 1
class Point {
    int x;
    int y;

public:
    // 복사 생성자
    Point(const Point& rhs)
        : x { rhs.x }
        , y { rhs.y }
    {
        cout << "Point(const Point&)" << endl;
    }

    Point(int a, int b)
        : x { a }
        , y { b }
    {
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt1 { 10, 20 };
    pt1.Print();

    // Point pt2 = pt1; // Copy Initialization
    // Point pt2(pt1);  // Direct Initialization
    // Point pt2 = { pt1 }; // Uniform Copy Initialization
    Point pt2 { pt1 }; // Uniform Direct Initialization

    pt2.Print();
}
#endif

#if 0
class Sample {
};
// 1) 아무일도 하지 않는 기본 생성자
// 2) 멤버를 복사하는 복사 생성자
int main()
{
    Sample s;
    Sample other = s;
}
#endif

#if 0
class Sample {
public:
    Sample(const Sample& rhs) { }
};
// => 복사 생성자도 생성자이기 때문에, 컴파일러는 아무일도 하지 않는
//    기본 생성자를 제공하지 않습니다.

int main()
{
}
#endif

// cppcon.org

// Effective Series, 스콧 마이어스
//  - Effective C++
//  - More Effective C++
//  - Effective STL
//  - Effective Modern C++, 류광 역 => C++11/14, *
