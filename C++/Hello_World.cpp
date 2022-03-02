#include <iostream>

using namespace std;    // 이걸쓰면 앞에 std를 붙이지 않아도 된다. 하지만 처음 배우는 입장이니 한동안은 쓰지 않도록....

int main() {
    std::cout << "I Love C++\n";
    std::cout << "I Love C++" << std::endl;
    std::cout << "I Love " << "C++" << std::endl;
    printf("Hello World!\n");
    printf("%s\n", "I Love Korea");

    for(int i = 0; i<3; ++i) {
        std::cout << i << std::endl;    // std:endl -> \n과 같은 역활 end line 약자?
        printf("%d\n", i);  // 난 이게 편하다...
        std::cout<< "i = " << i << std::endl;    // 문자열과 변수를 동시에 쓰려면 << 연산자로 연결한다
        std::cout<< i + "Hello World" << std::endl; // 이렇게 써버리면 앞에 글자의 시작부분을 설정하게 된다 ex) i = 1 2번째 문자부터 시작
        std::cout<< "Hello World" + i << std::endl; // 이렇게 써도 마찬가지...
    }
    return 0;
}
