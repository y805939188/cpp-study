#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
 */

class Base1 {
  public:
    int a;
    Base1(int n): a(n) {};
    void Print() {
      cout << "这里是 Base1" << endl;
    };
};

class Base2 {
  public:
    int b;
    Base2(int n): b(n) {};
    void Print() {
      cout << "这里是 Base2" << endl;
    };
};

class Other1 {
  public:
    double x;
    Other1(double n): x(n) {};
    void Print() {
      cout << "这里是 Other1" << endl;
    };
};

class Test1: public Base1, public Base2 {
  public:
    char c;
    Other1 d;
    Test1(int n1, int n2, double n3, char s1):Base1(n1), Base2(n2), d(n3) {
      /**
       * 一个类可以多继承
       * 也可以直接初始化父类 调用父类的构造函数
       * 还可以同时初始化自己内部的成员属性
       * 
       * 如果自己不明确写出Base1 Base2 Other1的构造函数调用的话 那编译器会自动调用
       * 
       * 构造函数的调用顺序是
       *  先调用老子的构造 再调用成员属性的构造函数 最后调用自己的构造的函数体内部代码
       *  在调用老子的构造的时候 会看class Test1: xxx, yyy 这个xxx和yyy的顺序
       */
      this -> c = s1;
      cout << "Test1的构造被调用" << endl;
    };
    ~Test1() {
      /**
       * 对于析构函数 调用顺序是和构造相反
       * 先调用子类 再调用成员属性 最后才是他的父类的析构函数
       */
    };
    void Print() {
      Base1::Print();
      Base2::Print();
      // Other1::Print(); // 他没法调用Other1的成员方法
      d.Print(); // 但是可以通过实例化成员属性为Other1来调用
    }
};


int main(void) {
  Test1 test1(6, 8, 88.88, 'd');
  test1.Print();
  return 0;
}
