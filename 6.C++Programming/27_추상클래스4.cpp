// 27_추상클래스4.cpp
#include <iostream>
using namespace std;

// 인터페이스
// => 교체 가능한 유연한 설계

// 인터페이스 문제점
// => 인터페이스에 새로운 기능을 추가하기 어렵습니다.
//    인터페이스에 새로운 기능을 추가하면, 기존에 인터페이스를 구현하는
//    모든 클래스가 해당 기능을 반드시 제공해야 합니다.
//    제공하지 않는다면, 추상 클래스가 되어 객체를 생성할 수 없습니다.

// ISP(Interface Segregation Principle, 인터페이스 분리 원칙)
//  : 범용 인터페이스보다 세분화된 인터페이스가 좋다.

class MP3 {
public:
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;
    // virtual void PlayOneMinute() = 0;

    // Java 8 - Modern Java
    // : 인터페이스에서 기본 구현을 제공하는 기능이 추가되었습니다
    virtual void PlayOneMinute()
    {
        // ...
    }
};

class Car {
    MP3* mp3;

public:
    Car(MP3* p)
        : mp3 { p }
    {
    }

    void PlayMusic()
    {
        mp3->Play();
        mp3->Stop();

        mp3->PlayOneMinute();
    }
};

class Player : public MP3 {
public:
    void Play() override { }
    void Stop() override { }
};

int main()
{
    Player player;
    Car car { &player };

    car.PlayMusic();
}

// * 객체 지향 설계의 핵심
//  => SOLID, 로버트 C 마틴(클린 코드) 정리
//  1) SRP(단일 책임 원칙)
//  2) OCP(개방 폐쇄 원칙)
//  3) LSP(리스코프 치환 원칙)
//  4) ISP(인터페이스 분리 원칙)
//  5) DIP(의존관계 역전 원칙)
