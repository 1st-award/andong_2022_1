#include <iostream>

using namespace std;
template <class T>
class CAdd {
    T num1, num2;
public:
    CAdd(T a, T b): num1(a), num2(b){}
    void Pr() {
        cout << num1+num2 << endl;
    }
};

int main(void) {
    CAdd <int> cAdd(3, 5);
    CAdd <double> cFAdd(2.5, 5.3);
    cAdd.Pr();
    cFAdd.Pr();
}