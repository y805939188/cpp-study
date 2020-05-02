#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
 */

void ff(int x) { cout << "ff(int x)" << endl; };
void ff(long x) { cout << "ff(long x)" << endl; };
void ff(float x) { cout << "ff(float x)" << endl; };

enum MyEnum {
  ding1 = 666,
  ding2 = 888,
};

void ff(MyEnum x) { cout << "ff(MyEnum)" << endl; };

void ff(int *const p) {}; // 表示指针本身是个const
// void ff(int *p) {}; // 和上面的一样 c++编译器会认为他俩一样导致不能正常编译

void ff(const int* p) {}; // 表示指向的int是个const

int main(void) {

  // ff(3.14); // 由于没有参数是double类型的 所以这里产生了二义性 会报错

  ff(666); // ff(int x) 不会调用枚举
  // 想重载到枚举那里的话
  MyEnum a = ding1;
  ff(ding1); // ff(MyEnum) 这样才能正确找到枚举
  ff(ding2); // ff(MyEnum) 这样也行

  return 0;
}
