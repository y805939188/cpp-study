#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
 */

int add1(int& a) {
  a++;
  return a;
}

int& add2(int& a) {
  a++;
  return a;
}


/**
 * 以下两种写法可以通过编译
 * 但是不要这么写
 * 不要return一个局部变量的指针或引用
 * 因为当函数体执行完毕之后局部变量都会被回收
 * 
 */
int* test1(void) {
  int a = 666;
  int* b = &a;
  return b;
}

const string& test2(void) {
  string a("66666");
  return a;
}

int main(void) {

  int a = 666;
  int b;
  b = add1(a);
  b++;
  cout << a << endl; // 667 虽然add接收的是引用 但是return会把它复制一份儿
  cout << b << endl; // 668

  int c = 1;
  int &d = add2(c);
  d++;
  cout << c << endl; // 3 add2返回为引用类型 用d接受的时候也用引用类型接收
  cout << d << endl; // 3

  return 0;
}
