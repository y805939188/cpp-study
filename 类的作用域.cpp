#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
 */

int a = 666;

class A {
  public:
    // explicit 表示这个构造函数不能自己隐式初始化成员属性
    // 创建类的时候必须传参
    explicit A(const int& num): a(num), b(num){};
    void myPrint() const {
      b++;
      cout << b << endl; // 889
      cout << a << endl; // 888
      cout << ::a << endl; // 666 ::是全局作用于符号
    }

  private:
    int a;
    mutable int b; // mutable 就可以在const的函数体内改了
};

int main(void) {
  A test1(888);
  A* test2 = &test1;
  test2 -> myPrint();
  return 0;
}
