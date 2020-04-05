#include <iostream>
#include "DingTest.h"
using namespace std;

DingTest::DingTest() {
  _a = 0;
  cout << "执行了默认的构造函数" << endl;
}
// 返回一个引用 等号的重载要这么写 加上 &
DingTest& DingTest::operator= (int a) {
  _a = a;
  return *this; // 返回当前对象的this的间接引用
}

DingTest& DingTest::operator= (const DingTest& x) {
  _a = x._a;
  return *this;
}

void DingTest::printDingTest () {
  cout << this << endl; // 返回一个类似 0x7ffeexxxxx 的地址
}

