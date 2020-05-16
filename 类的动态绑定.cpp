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
    // 如果这里不加virtual的话 就算子类写也写了MyOutput 那下面的动态绑定都会走这个父类函数
    void virtual MyOutput() const {
      /**
       * 下面的这个函数中
       * void DingPrint1(const Animal &animal) {
       *   animal.MyOutput();
       * };
       * 它的形参是const常量类型 意味着animal中的东西不可变
       * 但是无法保证MyOutput中是否有什么有副作用的操作
       * 所以会报错
       * 但是如果在这个Animal的成员函数MyOutput上加上 const 类型
       * 就表示这个函数中不会有什么副作用 所以就不会报错了
       */
      cout << "这里是基类" << endl;
    };
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
    void MyOutput() {
      cout << "这里是派生类" << endl;
    };
    void MyPrint() {
      cout << this -> b << endl;
    };
};

void DingPrint1(const Animal &animal) {
  animal.MyOutput();
};

void DingPrint2(Animal * animal) {
  // 这个MyOutput只有在被调用的时候才能知道执行的到底是子类还是父类的Print 这叫动态绑定
  animal -> MyOutput();
}

int main(void) {
  Animal* test1[2];
  test1[0] = new Animal(); // 一个指向基类的指针 可以指向基类
  test1[1] = new Dog(1); // 也可以指向派生类
  cout << test1[0] -> a << endl; // 0

  Animal test2;
  DingPrint1(test2);
  DingPrint2(test1[0]); // 这里是基类
  DingPrint2(test1[1]); // 这里是派生类
  return 0;
}
