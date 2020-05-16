#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * allocator 类
 *  可以分配职能大小的内存
 * RTTI 对象类型识别
 *  当不能使用虚函数的时候用它
 */

class Ding {
  public:
    int ding1;
    Ding() {
      this -> ding1 = 666;
    };
};

class A {};

class B: public A {};

class C {
  public:
    string a;
    string b;
    C() {
      a = "ding1";
      b = "ding2";
    }
    double test(std::size_t a) const { return 88.88; };
};

class D {
  public:
    class E {

    };
};

union F {
  int a;
  char b;
  double c;
};

int main(void) {
  /** allocator 类 */
  Ding ding1;
  cout << sizeof(ding1) << endl; // 4
  allocator<Ding> ding2;
  ding2.allocate(100); // 用来做内存分配的
  cout << sizeof(ding2) << endl; // 1


  /** RTTI */
  A* a = new A();
  // B* b = a; // 不可
  A* aa = new B(); // 可以 把派生类转为基类
  // B* b = dynamic_cast<B*>(a); // dynamic_cast 是动态检测

  /** 类成员的指针 */
  // string C::* p = &C.a; // 表示 p 是一个指针 这个指针指向 C 的 string 类型的成员
  // 表示 pp 是一个指针 指向C的成员的指针 并且是指向一个函数
  // 函数的参数是 std::size_t 类型的 返回值是double类型
  // 并且函数体是 const
  double(C::* pp)(std::size_t) const = &C::test;


  /** 嵌套类 */
  D::E e;


  /** union 联合类型 sizeof是按照里面最大的算的 比如上面的 F */
  // 把字母a保存在f中 首先变成ascii码的97
  // 然后由于a是第一个char类型的 char占1字节
  // 剩下的b和c都是空的 所以读取的话会输出97的'a'
  F f = { 'a' };
  cout << f.b << endl; // a


  /** 局部类 */
  // 就是一个类写在函数中


  /** 位域 */
  typedef unsigned int Bit; // 位域一般用无符号的整数来做
  class Test1{
    public:
      Bit a: 2;
      Bit b: 1;
      Bit c: 3;
      Bit d: 6;
      Bit e: 8;
      // ...
  };
  // 就相当于说 unsigned int 无符号的整形有4字节 也就是32位
  // 给 a 2位 b 1位 c 3位 d 6位 e 8位 这样的
  enum { A = 01, B = 02 };
  Test1 g;
  g.a = B; // 因为Test1的a只有2位 所以要么等于0要么等于1要么等于3
  g.b = 0; // b只有1位 所以要么等于0 要么等于1


  /** volatile 告诉c++ 该变量容易丢失 */
  volatile int x;
  // 告诉c++ 这个变量容易丢失 挥发性质的
  // 因为c++ 经常在优化的时候会改变该变量在内存的位置 加上这个就不会改变位置了


  /** extern "C" 用来做C 和 C++ 混合写的 */
  // extern "C" void xxx(char *); // 意思就是说 这个xxx是外部文件定义的函数 并且是C语言的

  return 0;
}
