#include "iostream"
using namespace std;

class ClassTest {  
  public:  
    ClassTest() {  
      c[0] = '\0';
      cout<<"ClassTest()"<<endl;
    }  
    ClassTest& operator=(const ClassTest &ct) {  
      strcpy(c, ct.c);
      cout<<"ClassTest& operator=(const ClassTest &ct)"<<endl;
      return *this;
    }
    ClassTest(const char *pc) {
      strcpy(c, pc);
      cout<<"ClassTest (const char *pc)"<<endl;
    }
    ClassTest(const ClassTest& ct) {  
      strcpy(c, ct.c);
      cout<<"ClassTest(const ClassTest& ct)"<<endl;
    }
  private:  
    char c[256];
};

int main(void) {
  /**
   * 直接初始化比复制初始化要更好
   * 因为直接初始化时用括号提供一个参数
   * 不会生成临时对象
   * 比如 int a(5)
   * 编译器会直接去找和5最匹配的构造函数也就是int这个内置类
   * 然后调用 int 的初始构造函数
   * 并
   * 
   * 而复制初始化(拷贝初始化)是 总是调用复制构造函数 也就是拷贝构造函数 (const int &num)
   * 复制初始化首先使用指定构造函数创建一个临时对象
   * 然后用复制构造函数将那个临时对象复制到正在创建的对象
   * 也就是相当于在拷贝构造函数中 先直接 int xxx(param) 然后再把这个xxx给copy到当前正在创建中的函数
   * 但是现在编译器会做优化 在自己没有定义拷贝构造函数的时候 编译器会自己创建在public中
   * 同时会走和直接初始化一样的逻辑
   * 拷贝初始化发生在下列情况：
   *    使用赋值运算符定义变量 (就是用等号赋值时候)
   *    将对象作为实参传递给一个非引用类型的形参
   *    将一个返回类型为非引用类型的函数返回一个对象
   *    用花括号列表初始化一个数组中的元素或一个聚合类中的成员
   */
  int test2(1024); // 直接初始化
  int test3 = 1024; // 复制初始化

  cout<<"ct1: ";
  ClassTest ct1("ab");//直接初始化
  cout<<"ct2: ";
  ClassTest ct2 = "ab";//复制初始化

  /**
   * 另外 写在main函数或者其他函数中的局部变量
   * 如果没有进行初始化的话 那就不能使用
   * 
   * 但是如果写在外边作为全局变量的话 编译器会默认初始化
   * 比如double就会初始化成 0.0
   */

  return 0;
}
