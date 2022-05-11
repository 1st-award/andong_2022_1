#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    ofstream MyFile("anu.txt"); // anu.txt 파일이 없으면 생성 후 열기
    MyFile << "20\n30\n40"; // anu.txt에 글 쓰기

    MyFile.close(); // 파일 닫기
}