#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 非引用形参
 * 1. 普通形参
 *  非const形参
 *  const形参
 * 2. 指针形参
 *  非const指针形参
 *  const指针形参
 * 
 * 引用形参
 * 
 * 
 * 建议所有不会发生改变的形参都定义为const形参
 * 因为const形参比较灵活
 */

void test1(int x) {
  // 非引用形参
  // 并没有把真正的a传进去
  // 而是把a给copy一下传进去
  // 所有的非引用形参都是copy
  x = x + 1;
}

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void test2(int *x) { // 相当于内存中开辟一个地址 这个地址对应的value就是实参传进来的那个地址
  // 指针形参 这里的指针形参也不是引用形参而是非引用形参
  // 所以也是copy
  // 相当于说把外部实参传进来的地址给copy一份儿
  *x = *x + 2;
  // cout << "这里test2的形参地址是" << (&x) << endl;
}

void test3(int& x) {
  // 引用形参
  // 引用就是别名 传进来的其实就是真正的实参
  // 而不是拷贝的值
  x = x + 3;
  // cout << "这里的test3的形参地址是" << (&x) << endl;
}

// 如果执行find_char(str, 'g')可以
// 但是不能直接find_char("ding test", 'g')
// 除非给find_char的签名变成find_char(const string &s, char c)
string::size_type find_char(string &s, char c) {
  string::size_type i = 0;
  while (i != s.size() && s[i] != c) i++;
  return i;
}
// string str("ding test");
// find_char(str, 'g');


void niubi(int *&v1, int *&v2) {
  // 传进来的是个指针 同时还是一个引用
  // 就是外部传进来的指针的别名
  cout << v1 << endl;
  cout << v2 << endl;
}
int main(void) {
  int a, b, c;
  a = 1;
  b = 1;
  c = 1;
  cout << "a加之前" << a;
  test1(a);
  cout << "------加之后------" << a << endl; // 1
  cout << "b加之前" << b;
  // cout << "这里的test2的实参地址是" << (&b) << endl;
  test2(&b);
  cout << "------加之后------" << b << endl; // 3
  cout << "c加之前" << c;
  // cout << "这里的test3的实参地址是" << (&c) << endl;
  test3(c);
  cout << "------加之后------" << c << endl; // 4

  int d = 1;
  int e = 2;
  cout << d << "  " << e << endl;
  swap(d, e);
  cout << d << "  " << e << endl;








  /**
   * 指向指针的引用形参
   * 
   */


  int g = 1;
  int h = 2;
  cout << "--------------" << endl;
  cout << &g << endl;
  cout << &h << endl;
  int *g_p = &g;
  int *h_p = &h;
  niubi(g_p, h_p); // 里面打印出来的和外部一样
  return 0;
}
