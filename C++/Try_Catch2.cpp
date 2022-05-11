#include <iostream>

using namespace std;
int main(void) {
    try {
        int age;
        cout << "How old are you? >>";
        cin >> age;

        if(age < 18)
            int* age = new int[100000000000000];
        cout << age << endl;
    }
    catch(exception e) {
        cout << e.what() << endl;
    }
}