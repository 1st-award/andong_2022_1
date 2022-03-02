#include <iostream>
#include <string>

// using namespace std;
int main() {
    std::string name;

    std::cout<<"What is Your Name? : ";
    std::getline(std::cin, name); // 공백을 구분하지 않는다
    // std::cin >> name;   // cout과 cin의 화살표(>)방향을 조심하자, 공백을 구분한다
    // scanf("%s", &name); // 아쉽게도 scanf로는 string형을 입력 받을 수 없다. (getline이나 char배열등을 이용하여 string형 입력을 받을 수 있다)
    std::cout<<"Hello " << name << "!\n";

    return 0;
}