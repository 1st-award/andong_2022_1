// 수업시간에 학습한 도형으로부터 두 정수를 상속 받고, 면적 계산하는 과정을 함수 오버라이딩을 통해 다형성을 구현하고, 실예를보이시오.
#include <iostream>

using namespace std;

class CPoly {
protected:
    int w, h;
public:
    virtual void Pr() = 0;
};

class CRect: public CPoly {
public:
    CRect(int a, int b) {
        w = a;  h = b;
    }
    void Pr() {
        cout << w * h << endl;
    }
};

class CTri: public CPoly {
public:
    CTri(int a, int b) {
        w = a;  h = b;
    }
    void Pr() {
        cout << w * h / 2 << endl;
    }
};

int main(void) {
    CPoly* c;
    CRect r(4, 2);
    CTri t(2, 3);

    c = &r; c->Pr();
    c = &t; c->Pr();
}
