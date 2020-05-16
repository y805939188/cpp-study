#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 继承类也叫派生类
 */

class Animal {
  public:
    int a;
  protected: // 专门给继承类使用的
    double b;
  private:
    string c;
};

class Dog: public Animal {
  public:
    // Dog(double num): b(num) {}; // 不能这样写 会报错的
    Dog(double num) {
      this -> b = num;
    };

    void MyPrint() {
      cout << this -> b << endl;
    };
};

int main(void) {
  Animal test1;
  Dog test2(66.66);
  cout << test2.a << endl; // 0 没有初始化时候是 0
  // cout << test2.b << endl; // 报错
  // cout << test2.c << endl; // 报错
  test2.MyPrint(); // 66.66
  return 0;
}
