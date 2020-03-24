#include <iostream>
#include "./mylib/ding.h"

// g++ index3.cpp -lcurses ./mylib/** -o index3 && ./index3
// 
using namespace std;

int getInt(int a) {
  return a + 100;
}

int getIntWrapper(int a, int(*p)(int)) {
  return p(a);
}

int main()
{
  // 函数指针
  // 函数也是在内存中占用一段儿内存单元 有个起始地址
  int(*p)(int) = func; // 一个指针 函数返回数据类型(*指针名称)(参数表)
  int* pp(int); // 一个函数 返回的类型是一个指针

  cout << 111 << ':' << getIntWrapper(6, getInt) << endl; // 输出106

  int result = ding::test(7);
  cout << 222 << ":" << result << endl;

  // char* strcpy(char* dest, const char* src) // 这个字符串拷贝就是 返回一个指针 一个指向字符串的指针

  int res1 = func(1);
  cout << res1 << endl;
  int res2 = func(2.0);
  cout << res2 << endl;
  int res3 = func(1, 2.0);
  cout << res3 << endl;
  return 0;
}
