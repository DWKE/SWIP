// 13_stack.cpp
#include <iostream>
using namespace std;

#if 0
int buff[10];
int top = 0;

void Push(int n)
{
    buff[top++] = n;
}

int Pop()
{
    return buff[--top];
}

int main()
{
    Push(10);
    Push(20);
    Push(30);

    cout << Pop() << endl;
    cout << Pop() << endl;
    cout << Pop() << endl;
}
#endif

// 데이터 캡슐화
#if 0
struct Stack {
    int buff[10];
    int top;
};

void Init(Stack* s)
{
    s->top = 0;
}

void Push(Stack* s, int n)
{
    s->buff[(s->top)++] = n;
}

int Pop(Stack* s)
{
    return s->buff[--(s->top)];
}

int main()
{
    Stack s;

    Push(&s, 10);
    Push(&s, 20);
    Push(&s, 30);

    cout << Pop(&s) << endl;
    cout << Pop(&s) << endl;
    cout << Pop(&s) << endl;
}
#endif

#if 0
struct Stack {
    int buff[10];
    int top;

    void Init(/* Stack* this */)
    {
        this->top = 0;
    }

    void Push(/* Stack* this */ int n)
    {
        this->buff[(this->top)++] = n;
    }

    int Pop(/* Stack* this */)
    {
        return this->buff[--(this->top)];
    }
};

int main()
{
    Stack s;

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}
#endif

// C++ 캡슐화
//  : 상태(멤버 데이터) + 행위(멤버 함수)
// - 객체의 상태는 멤버 함수를 통해 접근되어야 합니다.
// => 정보 은닉(Information Hiding)
//   "접근지정자"
//   - private
//   - public

// 객체를 위한 사용자 정의 타입은 struct 보다는 class를 사용하는 것이 좋습니다.
// => class의 기본 접근 지정자는 private 입니다.

// * 객체는 생성 이후에 바로 사용할 수 있어야 합니다.
// => 생성자(Constructor) 함수
#if 0
class Stack {
private:
    int buff[10];
    int top;

public:
    Stack()
    {
        top = 0;
    }

    void Push(int n)
    {
        buff[top++] = n;
    }

    int Pop()
    {
        return buff[--top];
    }
};

int main()
{
    Stack s;
    // 상태와 행위를 가지는 변수 => 객체(object)
    // s.Init();

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}
#endif

// 객체가 메모리를 할당한 경우,
// 객체가 파괴되기 이전에 반드시 해당 메모리를 해지해야 합니다.
// => 객체가 파괴되기 직전에 호출되는 약속된 멤버 함수
//    : 소멸자(Destructor) 함수
#if 0
class Stack {
private:
    int* buff;
    int top;

public:
    ~Stack()
    {
        delete[] buff;
    }

    // 파라미터 기본값은 불필요한 오버로딩을 제거할 수 있습니다.
    Stack(int size = 10)
    {
        buff = new int[size];
        top = 0;
    }

    void Push(int n)
    {
        buff[top++] = n;
    }

    int Pop()
    {
        return buff[--top];
    }
};

int main()
{
    // Stack s(100); // Stack(int)
    Stack s { 100 }; // Stack(int)

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}
#endif

// template <typename T>

// 템플릿은 타입 인자를 지정할 때
//   typename 또는 class를 이용하면 됩니다.
template <class T>
class Stack {
private:
    T* buff;
    int top;

public:
    ~Stack()
    {
        delete[] buff;
    }

    Stack(int size = 10)
    {
        buff = new T[size];
        top = 0;
    }

    // * void Push(T n)
    //  T -> int
    //   : void Push(int n)
    //  T -> string
    //   : void Push(string n)

    // 함수가 템플릿 타입을 인자로 전달받는 경우에는
    // 객체 타입을 대상으로 불필요한 복사 생성/제거 비용을 제거하기 위해서
    // 템플릿 인자도 const T& 형태로 만듭니다.

    // * void Push(const T& n)
    //  T -> int
    //   : void Push(const int& n)
    //  T -> string
    //   : void Push(const string& n)
    void Push(const T& n)
    {
        buff[top++] = n;
    }

    void Pop() { --top; }

    T& Top() { return buff[top - 1]; }
    const T& Top() const { return buff[top - 1]; }

#if 0
    T Pop()
    {
        return buff[--top];
    }
#endif
};

#if 0
// 클래스 템플릿은 타입 추론이 불가능한 경우가 많습니다.
// 명시적으로 타입을 지정해야 합니다.
int main()
{
    Stack<int> s { 100 }; // Stack(int)

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}
#endif

#include <string>

int main()
{
    Stack<string> s;

    s.Push("hello");
    s.Push("world");
    s.Push("money");

    // cout << s.Pop() << endl;
    // cout << s.Pop() << endl;
    // cout << s.Pop() << endl;
    cout << s.Top() << endl;
    s.Pop();
    cout << s.Top() << endl;
    s.Pop();
    cout << s.Top() << endl;
    s.Pop();
}

// * top = 1;
// 4: [    ]
// 3: [    ]
// 2: [    ]
// 1: [    ]
// 0: [ 10 ]  <-- 유효 영역

// * top = 2;
// 4: [    ]
// 3: [    ]
// 2: [    ]
// 1: [ 20 ]  <-- 유효 영역
// 0: [ 10 ]

// * top = 1;
// 4: [    ]
// 3: [    ]
// 2: [    ]
// 1: [ 20 ]
// 0: [ 10 ]  <-- 유효 영역
