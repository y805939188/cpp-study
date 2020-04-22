#include "iostream"
using namespace std;

int main(void) {
  const int a = 10;
  int* p_a = const_cast<int*>(&a); // const_cast 可以让p_a临时改变
  cout << p_a << endl;
  *p_a = 666;
  cout << *p_a << endl; // 666
  cout << a << endl; // 10 不影响原来的const

  // 通过typedef可以定义一个类型
  // 返回值是void类型 并且没有参数的 函数指针
  typedef void(*Func)();
  /**
   * 任何声明变量的语句前面加上typedef之后 原来是变量的都变成一种类型
   * 不管这个声明中的标识符号出现在中间还是最后 
   */
  typedef int NUM;
  NUM ding1 = 10; // 也可写成`NUM(ding1) = 10;`
  NUM(ding2) = 12; // 也可写成`NUM ding2 = 12;`

  typedef int x; // 定义了一个名为x的int类型
  typedef struct { char c; } s; // 定义名为s的struct类型
  // struct { char c; } b; // 结构体
  typedef int *p; //定义了一个名为p的指针类型 它指向int
  // int yu = 88;
  // p i = &yu; // i 已经变成一个 int* p 类型的指针
  typedef int A[];  // 定义一个名为A的ints数组的类型
  typedef int f(); // 定义一个名为f, 参数为空, 返回值为int的函数类型
  typedef int g(int); // 定义一个名为g, 含一个int参数, 返回值为int行的函数类型
  typedef int P(); // 简单的
  typedef void Q(int *p, const std::string& s1, const std::string& s2, size_t size, bool is_true); // 复杂的
  class X {
  public:
    P(eat_shit); // 等价于声明`int eat_shit();`
    Q(bullshit); // 等价于声明`void bullshit(int *p, const string& s1, const string& s2, size_t size, bool is_true);`
  };

  return 0;
}
