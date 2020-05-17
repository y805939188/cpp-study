#include "iostream"
using namespace std;

/**
 * 可以使用 typedef 定义同义词 
 */

// 相当于说把int起了个名为分数的同义词
typedef double 分数;

// 定义一个结构体 起个同义词叫MyName
typedef struct {
  分数 a;
  int b;
} MyName;

class Test {
  public:
    typedef int ding;
};

template <class T>
class Test2 {
  public:
    const static int ding1 = 666;
    static void ding2(void) { cout << "静态成员函数" << endl; };
    typedef T ding3;
};

class Test3 {
  public:
    /**
     * Test2<int>::ding3; 这个东西 模板在编译之前其实不知道他到底是个啥东西
     * 有三种可能 可能是静态成员属性 静态成员函数 和typedef定义的嵌套类型 或者说类型别名
     * 所以在 typedef 后面加个 typename 就能让语义更加明确
     * 也就是说 typename 告诉编译器 Test2<int>::ding3 是一个类型而不是一个成员
     */
    // typedef Test2<int>::ding3  new_ding3;
    typedef typename Test2<int>::ding3  new_ding3;
    void test(void) {
      int aa = Test2<int>::ding1;
      cout << aa << endl; // 666
      Test2<int>::ding2(); // 输出静态成员函数
      Test3::new_ding3 bb = 888;
      cout << bb << endl; // 888
    }
};

int main(void) {
  // 如果写个int类型的话 那就只是个int类型
  // 但是如果有个同义词的话 那就一下能知道 a 是个分数类型
  // 而且如果有别的很复杂的类型的话 可以定义个简单明了的类型名字
  分数 a = 66.66;

  Test::ding b = 88;
  cout << b << endl; // 88

  Test3 c;
  c.test();
  return 0;
}
