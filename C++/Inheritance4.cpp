#include <iostream>

using namespace std;

class CAuto {
public:
    virtual void OutEngine() = 0;
};

class CSonata: public CAuto {
public:
    void OutEngine() {
        cout << "6" << endl;
    }
};

class CGenesis: public CAuto {
public:
    void OutEngine() {
        cout << "8" << endl;
    }
};

int main() {
    CAuto* cAuto;

    cAuto = new CSonata();
    cAuto->OutEngine();

    cAuto = new CGenesis();
    cAuto->OutEngine();
}
