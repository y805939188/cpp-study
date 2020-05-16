#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 从基类转换成子类是不允许的
 * 但是从子类转换成父类是允许的
 */

class Base1 {
  public:
    virtual void Print() const {
      cout << "我是爹" << endl;
    }
};

class Test1: public Base1 {
  public:
    void Print() const {
      cout << "我是儿子" << endl;
    }
};

// void MyPrint(const Base1 item) {
//   item.Print();
// };

void MyPrint(const Base1* item) {
  item -> Print();
}

void MyPrint(const Base1& item) {
  item.Print();
}

int main(void) {
  Test1 test1;
  /**
   * 在没有 void MyPrint(const Base1& item) 的情况下
   * 输出 爹 不管是不是虚函数 都是 die
   * 说明这里基类作为函数的形参的话 如果直接传会隐式转换成父类
   */
  // MyPrint(test1); // 我是爹

  /**
   * 传指针的话会进行函数重载 重载到子类
   * 但是注意父类得加virtual变成虚函数
   */
  // MyPrint(&test1); // 传指针 我是儿子

  /**
   * 传引用 void MyPrint(const Base1& item) 的情况下
   * 输出 我是儿子
   * 和传指针一样 说明发生了函数重载
   */
  MyPrint(test1); // 走传引用

  /**
   * 基本上不存在父类转换成子类的情况
   * 
   * 除非使用强制类型转换
   */

  Test1 test2;
  Base1* p1 = &test2; // 子转父是可以的
  Base1* p2 = static_cast<Base1 *>(& test2);

  Base1 test3;
  // Test1* p3 = &test3; // 父转子就会报错
  Test1* p4 = static_cast<Test1 *>(& test3); // 父转子 强制转换是可以的 不过基本不会用到
  return 0;
}
