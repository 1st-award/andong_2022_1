#include <iostream>
#include <string>

using namespace std;
int main(void) {
    int num = 15;
    try {
        if(num < 18) {
            throw num;
        }
    }
    catch (int num) {
        cout << "No Pass " << num << endl;
    }
    return 0;
}