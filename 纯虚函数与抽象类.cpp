#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 一个类中包含一个或多个纯虚函数的 就是抽象类
 * 抽象类不能被创建 只能去继承
 * 然后子类必须要实现这个抽象类的虚函数
 * 
 * c++规定 如果一个基类中有虚函数
 * 那它的派生类中的同名函数自动变成虚函数
 * 前面可以加 virtual 也可以不加
 * 但是最好加上 这样程序比较清晰
 */

class Shape {
  public:
    Shape() {};
    virtual ~Shape() {};
    /**
     * 下面这种直接让们 = 0 的就叫纯虚函数
     */
    virtual double GetArea() = 0;
    virtual double GetPerim() = 0;
    virtual void Draw() = 0;
    void Print() {
      cout << "可以写一些正常的方法" << endl;
    };
};

class Shape2 {
  public:
    /**
     * 含有虚函数但是不是纯虚函数的时候
     * 可以直接实例化 并不是一个抽象类
     */
    void virtual Print() {
      cout << "这是一个非纯虚函数" << endl;
    };
};

class Circle: public Shape {
  // 如果Circle 没有全覆盖住Shape的虚函数的话
  // 那Circle也不能被实例化 它自己也变成了一个抽象类
};

class Circle2: public Shape {
  public:
    Circle2() {
      cout << "Circle2的构造函数" << endl;
    };
    /**
     * 只要类中有任何一个成员函数是虚函数
     * 那就一定要把析构函数写成虚函数
     */
    virtual ~Circle2() {};
    double GetArea() {};
    double GetPerim() {};
    void Draw() {};
    /**
     * 如此把父类中的虚函数都覆盖了之后 就变成一个正常类了 可以实例化
     */
};

class Circle3: public Shape2 {

};

int main(void) {
  // Shape test1; // 报错 不能实例化 只能继承
  Circle2 test2;
  test2.Print();
  Circle3 test3;
  test3.Print();
  Shape2 test4;
  test4.Print();
  return 0;
}
