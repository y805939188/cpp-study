#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
 */

class Test {
  /**
   * 如果一个类中定义了一个析构函数的话 并且析构中药delete一些成员指针的话
   * 基本上一定要自己定义拷贝构造和赋值操作符
   * 
   * 因为编译器自己创建的只是简单地把指针复制
   * 所以可能会导致 delete 同一个指针两次
   */
  public:
    Test() { cout << "构造函数被调用" << endl; };
    // 复制构造函数 也叫拷贝构造
    // 如果不写 c++会默认帮创建
    // 自动创建的叫合成拷贝构造
    // 作用就死把传进来的test中所有的成员赋值到一个新的对象中
    Test(const Test& test): a(test.a), b(test.b) { cout << "拷贝构造被调用" << endl; };

    // 赋值操作符
    // 不写的话 c++会默认加上
    Test& operator= (const Test& test) {
      cout << "赋值操作符被调用" << endl;
      a = test.a;
      b = test.b;
      return *this;
    };

    // 一般情况下可以不用写上面那俩 因为c++会默认创建

  private:
    int a = 1;
    int b = 2;
};

Test foo(Test test) { // 首先传参的时候不是引用所以发生一次copy构造 按引用传参就不会调用拷贝构造
  Test test1; // 默认构造被调用
  test1 = test; // 赋值操作符被调用
  return test1; // 返回的时候由于函数体内局部变量被销毁 所以按理说应该又触发一次拷贝构造 如果返回引用也不会触发拷贝构造
}

class Ding {
  public:
    Ding(int num = 6): p(new string), a(num) {};
    // 如果成员属性有指针的话 就得自己写拷贝构造
    // 因为c++内部处理的不是很好
    // 拿到other中的p 然后*解除指针 然后重新创建一个string
    // c++内部默认的 是直接 p(other.p) 把指针给他了
    Ding(const Ding& other): p(new string(*(other.p))), a(other.a) {};
    Ding& operator= (const Ding& other) {
      p = new string;
      *p = *(other.p);
      // c++写的是直接把 p = other.p 直接把指针给他了
      a = other.a;
    };
  private:
    string *p;
    int a;
};

int main(void) {
  Test test1; // 构造函数被调用
  Test test2(test1); // 拷贝构造被调用 这种就是拷贝构造
  Test test3; // 构造函数被调用
  test3 = test2; // 赋值操作符被调用
  cout << "-----------------" << endl;
  Test res;
  res = foo(test1); // 这里最后拿到返回值的时候没有触发拷贝构造 这特么是为啥
  return 0;
};
