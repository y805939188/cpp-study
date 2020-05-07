#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 友元分为两类
 * 1. 友元函数
 * 2. 友元类 一个类可以作为另外一个类的朋友 也就是这个类可以操作另外一个类的成员
 */

class Test;

class MyClass {
  public:
    void myFn2(Test&);
};

class Test {
  public:
    typedef string::size_type index;
    Test(const int h = 0, const int w = 0): height(h), width(w){};

    // 自己内部可以使用height和width 但是外部不行
    // 不过
    friend int area(Test &); // 友元函数 这个函数中可以使用这个class的private

    friend class FriendClass; // 友元类 这个类中的函数可以使用这个class的private

    friend void MyClass::myFn2(Test&); // 还可对某个class中单独的某个函数作为友元 就是写起来比较麻烦 得在上面先声明 否则相互依赖找不到

  private:
    int height;
    int width;
};

int area(Test& test) {
  return test.height * test.width;
}

class FriendClass {
  public:
    void myFn(Test& test) {
      cout << test.height << ":::" << test.width << endl;
    };
};

void MyClass::myFn2(Test& test) {};

int main(void) {
  Test test(10, 10);
  const int myArea = area(test);
  cout << myArea << endl; // 100
  FriendClass fr;
  fr.myFn(test); // 10 10
  return 0;
}
