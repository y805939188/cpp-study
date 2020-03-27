#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex() {
  _a = 0.0;
  _b = 0.0;
  cout << "执行了默认的构造函数" << endl;
}


Complex::Complex(double a, double b) {
  _a = a;
  _b = b;
  cout << "执行了带参数的构造函数" << endl;
}

double Complex::getA() const {
  return _a;
}


double Complex::getB() const {
  return _b;
}

void Complex::setDoubleA(double c) {
  _a = c;
}

void Complex::setDoubleB(double d) {
  _b = d;
}

// 拷贝构造
Complex::Complex(const Complex& x) {
  // 这里自己把拷贝构造写出覆盖系统默认的拷贝构造
  // 以防止出现一些问题 比如这里传过来的 x 参数
  // 里面有可能会涉及到是否有堆空间的存在
  // 这样就会涉及到一个深拷贝浅拷贝的问题
  _a = x._a;
  _b = x._b;
  cout << "这里是拷贝构造" << endl;
}

Complex Complex::operator+ (const Complex& x) {
  // Complex temp; // 这里不会报错 因为有个不带参数的Complex默认构造函数
  // temp._a = _a + x._a;
  // temp._b = _b + x._b;

  // // 这里其实返回的是一个拷贝构造
  // // 因为上面的Complex temp的temp创建在了栈上
  // // 所以当这个函数体一结束 这个temp就没了被销毁了
  // // 但是在 = 运算符那里又想接收它作为参数
  // // 所以就给他拷贝了一份儿
  // // 也就是说 这里的temp和下面 = 等号重载时候接收的那个 x 参数
  // // 并不是同一个地址
  // return temp;

  // 当然也可以不用创建临时对象 直接这么返回也可以
  return Complex(_a + x._a, _b + x._b);
}

// 返回一个引用 等号的重载要这么写 加上 &
Complex& Complex::operator= (const Complex& x) {
  if (this == &x) {
    return *this;
  }
  _a = x._a;
  _b = x._b;
  return *this; // 返回当前对象的this的间接引用
}

Complex& Complex::operator++ () {
  _a++;
  _b++;
  // 一般都返回引用
  // 直接返回值的话 会产生拷贝构造
  return *this;
}

// 这里用一个int区分是前置还是后置 ↓
Complex Complex::operator++ (int) {
  // 为什么这里必须得用指针的形式
  Complex tmp(*this);
  _a++;
  _b++;
  // 还有为啥这里不能也返回一个指针
  return tmp;
}

void Complex::PrintVal () {
  cout << "这里的this是" << ':' << (this) << endl; // 打印一个地址
  // cout << "这里的this*是" << ':' << (*this) << endl;
}


Complex::~Complex() {
  cout << "执行了析构函数" << endl;
}
