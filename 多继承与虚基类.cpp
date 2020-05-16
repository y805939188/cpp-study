#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 多继承要小心二义性
 * 二义性的问题使用虚基类解决
 * 
 * 比如 C 继承了 A 和 B
 * A 和 B 都有个叫做 print 的方法
 * 这就叫二义性
 */

class X {
  public:
    int test;
};

class A: virtual public X {
  public:
    A () {
      this -> test = 666;
    };
    void print() {
      cout << "这是A" << endl;
    };
};

class B: virtual public X {
  public:
    B() {
      this -> test = 888;
    };
    void print() {
      cout << "这是B" << endl;
    };
};

class C: public A, public B {
  public:
    C() {
      this -> test = 666888;
    }
};

int main(void) {
  C test1;
  // test1.print(); // 会报错 因为print不明确
  test1.A::print(); // 这是A
  test1.B::print(); // 这是B
  C* test2 = new C;
  test2 -> A::print(); // 这是A
  test2 -> B::print(); // 这是B

  /**
   * 还有更操蛋的问题
   * 假如 A 和 B 都继承了 X
   * X 里有个 test 属性
   * 那就相当于 C 继承了俩一样的属性
   * 这叫菱形继承
   * 
   * 可以使用虚基类 专门解决这个问题
   */
  C* test3 = new C;
  /**
   * 对 A 和 B 进行改造
   * 让 A 和 B 都继承 X 的虚基类
   * 这样的话 C 再多继承 A 和 B 的时候
   * 就只有一个未初始化的 test
   * 所以 C 再对它爷爷 也就是 X 的 test 进行一下初始化
   * 就ojbk了
   * 如果再有个 D 继承了 C
   * 那 D 也必须再初始化一下它太爷爷 也就是 X 的 test
   */
  cout << test3 -> test << endl; //666888

  return 0;
}
