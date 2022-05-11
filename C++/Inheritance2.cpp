#include <iostream>

using namespace std;

class CPoly {
protected:
    int width, height;
};

class CRect: public CPoly {
public:
    CRect (int w, int h) {width = w; height = h;}
    void Pr() {
        cout << width * height << endl;
    }
};

class CTri: public CPoly {
public:
    CTri(int w, int h) {width = w; height = h;}
    void Pr() {
        cout << width * height / 2 << endl;
    }
};

int main(void) {
    CRect* p = new CRect(4, 6);
    CTri* t = new CTri(5, 7);
    p->Pr();
    t->Pr();

    delete(p);
    delete(t);
}