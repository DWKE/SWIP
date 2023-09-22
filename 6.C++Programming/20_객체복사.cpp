// 20_객체복사.cpp
#include <iostream>
using namespace std;

// 1) 객체 내부에서 자원을 할당한 경우,
//    소멸자를 통해서 자원을 해지해야 합니다.

// 2) 포인터 멤버를 가지는 클래스는
//    컴파일러가 제공하는 복사 생성자/대입 연산자를 사용하는 경우
//    "얕은 복사" 문제가 발생합니다.

// 3) 포인터 멤버를 가지는 경우,
//    반드시 복사 생성자/대입 연산자를 직접 제공해서,
//    문제를 해결해야 합니다.

// 핵심: 복사 정책을 구현하기 위해서는
//      반드시 복사 생성자와 대입 연산자를 함께 제공해야 합니다.

// 복사 정책
// 1) 깊은 복사 - 복사 생성자
// 2) 참조 계수 - 복사 생성자
// 3) 복사 금지 - 복사 생성자
// 4) 소유권 이전 - 이동 생성자

class User {
    char* name;
    int age;

public:
    // 컴파일러가 제공하는 복사 생성자/대입 연산자 형태
    User& operator=(const User& rhs)
    {
        name = rhs.name;
        age = rhs.age;

        return *this;
    }

    User(const User& rhs)
        : name { rhs.name }
        , age { rhs.age }
    {
    }

    User(const char* s, int n)
        : age(n)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        delete[] name;
    }

    void Print()
    {
        cout << name << ", " << age << endl;
    }
};

int main()
{
    User user1 { "Tom", 42 };
    user1.Print();

    User other = user1;
    other.Print();
}
