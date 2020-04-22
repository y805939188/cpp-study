#include "iostream"
using namespace std;

// #define MA(x) x*(x-1); // 用宏定义的话 就会输出8
// 因为 MA( 1 + a + b ) { return 1 + a + b * ( 1 + a + b - 1 ) };

int MA(int x) {
  return x*(x-1);
};

void ding(char* p) {
  // p 是一个指针 是一个指向指针的指针
  cout << "1:: " << &p << endl;
  // cout << "2:: " << *p << endl;
  p = new char[100];
}

int main() {
  // int a = 1, b = 2;
  // cout << MA(1 + a + b);

  // char test[100];
  // // cout << sizeof(test) << endl;

  char* str = NULL;
  ding(str);
  // str = new char[100];
  cout << "3:: " << &str << endl;
  return 0;
}

