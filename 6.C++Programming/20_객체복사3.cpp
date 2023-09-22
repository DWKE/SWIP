// 20_객체복사3.cpp
#include <iostream>
using namespace std;

// 복사 정책
// 2) 참조 계수 => 소유권 공유

class User {
    char* name;
    int age;
    int* ref;

public:
    User& operator=(const User& rhs)
    {
        if (this == &rhs) {
            return *this;
        }

        // 참조 계수를 감소하고, 자원을 정리합니다.
        if (--(*ref) == 0) {
            delete[] name;
            delete ref;
        }

        // 복사를 수행하고, 참조 계수를 증가시킵니다.
        name = rhs.name;
        age = rhs.age;
        ref = rhs.ref;
        ++(*ref);

        return *this;
    }

    User(const User& rhs)
        : name { rhs.name }
        , age { rhs.age }
        , ref { rhs.ref }
    {
        ++(*ref); // 참조 계수 증가!
    }

    User(const char* s, int n)
        : age(n)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);

        ref = new int { 1 };
    }

    ~User()
    {
        // 참조 계수가 0이 되면, 소유한 자원을 파괴합니다.
        if (--(*ref) == 0) {
            delete[] name;
            delete ref;
        }
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
