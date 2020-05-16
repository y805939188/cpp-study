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

class Dog_temp1: Animal {}; // 可以不写修饰符 默认是private形式的继承
struct Dog_temp2: Animal {}; // 这样写默认就是 public形式的继承

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

class Cat: private Animal {
  /**
   * 把Animal中所有的public和protected都变成私有的
   * 使用using Animal::xxx 可以恢复原始的那个修饰符
   * 以private的方式继承Animal 同理还有protected
   */
  public:
    using Animal::a; // 把Animal中共有的a变回public的
    void MyFn() {
      cout << this -> a << endl;
      cout << this -> b << endl;
    }
};

class Pig: protected Animal {
  /**
   * 相当于把Animal中的public属性都变成protected 但是private的属性还是私有的
   */
  void MyFn() {
    cout << this -> b << endl;
    // cout << this -> c << endl; // 报错
  }
};

int main(void) {
  Animal test1;
  Dog test2(66.66);
  cout << test2.a << endl; // 0 没有初始化时候是 0
  // cout << test2.b << endl; // 报错
  // cout << test2.c << endl; // 报错
  test2.MyPrint(); // 66.66

  Cat test3;
  test3.MyFn();
  // cout << test3.a << endl; // 报错 因为Cat类是以private的方式继承Animal的

  Pig test4;
  // cout << test4.a << endl; // 也会报错
  return 0;
}
