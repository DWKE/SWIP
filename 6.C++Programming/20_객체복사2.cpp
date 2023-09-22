// 20_객체복사2.cpp
#include <iostream>
using namespace std;

// 깊은 복사
class User {
    char* name;
    int age;

public:
    //---
    User& operator=(const User& rhs)
    {
        // 1) 자기 자신이 대입인지 확인합니다.
        if (this == &rhs) {
            return *this;
        }

        // 2) 이미 자원을 소유한 경우, 해지해야 합니다.
        delete[] name;

        // 3) 깊은 복사
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
        age = rhs.age;

        return *this;
    }

    User(const User& rhs)
        : age { rhs.age }
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }
    //---

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
