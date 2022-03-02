#include <iostream>

class CRect {   // class는 c언어의 사용자지정함수 struct의 상위호한이다
    int w, h;
public: // public이외에 private protected가 있다 (default: private)
    void Set(int, int);
    int Area(){ // inline function. 클래스 속에서 구현한 함수, 속도가 빠르다
        return w * h;
    }
};

void CRect::Set(int w, int h) {
    this->w = w;
    this->h = h;
}

int main() {
    CRect r;
    r.Set(4, 5);
    std::cout << "(4, 5) Area is : " << r.Area();
    return 0;
}