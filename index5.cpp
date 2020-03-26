#include <iostream>
#include "myclass/Complex.h"
using namespace std;

class Student {
  private:
    string name;
    double score;
  public:
    double GetScore() {
      return score;
    }
};

int main(void) {
  // c++中可以通过 class和 struct来定义一个类
  // 他俩基本没区别 唯一的区别就是
  // struct的默认成员权限是pulic
  // class的默认的成员权限是private

  // Complex complex();
  Complex complex1(1.0, 2.0);
  Complex complex2(1.0, 2.0);

  cout << complex1.getA() << endl;
  cout << complex1.getB() << endl;
  complex1.setDoubleA(6.6);
  complex1.setDoubleB(8.8);
  cout << complex1.getA() << endl;
  cout << complex1.getB() << endl;

  // 这里可以直接用 = 因为c++内部自己对=做了个重载
  // 当然也可以自己重新写
  Complex complex3; // P.S. 直接写 Complex complex3 = complex1 + complex2 不是调用=的重载 而是叫做 "定义"
  complex3 = complex1 + complex2;

  cout << complex3.getA() << endl;
  cout << complex3.getB() << endl;

  Complex complex4 = Complex(9.9, 9.9);
  cout << complex4.getA() << endl;

  // 这种写法也可以 相当于直接调用了 拷贝构造
  Complex complex5(complex4);







  return 0;
}
