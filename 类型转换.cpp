#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 *
 */

class Animal {
  public:
    virtual void speak() = 0; // 这里必须写个虚函数 不然下面的dynamic_cast会报错
};

class Dog: public Animal {
  public:
    void speak() {
      cout << "niubi" << endl;
    }
};

void isDogOrOther(Animal* animal) {
  // dynamic_cast可以在运行时动态检测
  Dog *dog = dynamic_cast<Dog *>(animal); // 这里必须得告诉dynamic_cast animal是个抽象类
  if (dog) {
    dog -> speak();
  }
}

int main(void) {

  double Pi = 3.14;
  int num1 = static_cast<int>(Pi); // c++的方法
  int num2 = (int)Pi; // c的方法
  int num3 = Pi; // 会进行饮食类型转换 会丢失精度
  // 程序中最好避免强制类型转换

  // static_cast 是静态类型转换 在编译阶段会做一些检查

  Dog *dog = new Dog();
  isDogOrOther(dog);

  return 0;
}
