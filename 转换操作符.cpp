#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 转换操作符
 * public:
 *  operator xxx() const { return yyy }
 * 不能指定返回类型 但是 return 的yyy必须是xxx类型
 */

class Dog {
  public:
    Dog(int n, double m): age(n), age2(m) {};
    operator int() const { // 可以把Dog类型转换成int类型 不能指定返回类型 
      return this -> age;
    };
    operator double() const {
      return this -> age2;
    };
  private:
    int age;
    double age2;
};

int main(void) {
  int a, b;
  a = 10;
  b = a;

  Dog c(66, 88.88);
  b = c; // 直接等于一个dog类型会报错 因为c是个类
  double d = c;
  cout << b << endl; // 66
  cout << d << endl; // 88.88
  return 0;
}
