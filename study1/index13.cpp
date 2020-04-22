#include "iostream"
using namespace std;

/** 泛型编程 */

// 编译器会根据编译时候的输入生成对应类型的代码
template <class T>
T myMax(T a, T b) {
  return a > b ? a : b;
}

// 泛型的特化处理
template <>
char* myMax(char* a, char* b) {
  return "6666";
}

template <class T1, class T2>
int myMax(T1 a, T2 b) {
  cout << "6666" << endl;
  return (int)(a > b ? a : b);
}

template <int n>
class Sum {
  public:
    enum { N = Sum<n - 1>::N + n };
};

template <>
class Sum<1> {
  public:
    enum { N = 1 };
};

class Test {
  public:
    int liu = 888;
    enum { ding = 666 };
    // static int yu = 999; // 报错
    static int const yu = 999;
};

int main(void) {
  Test test;
  cout << test.ding << endl; // 666
  cout << Test::ding << endl; // 666
  // cout << Test::liu << endl; // 报错
  cout << test.liu << endl; // 888
  cout << Test::yu << endl; // 999
  cout << test.yu << endl; // 999


  // cout << myMax(1, 3) << endl;
  // cout << myMax(1.0, 3.0) << endl;
  // char* ding1 = "ding1";
  // char* ding2 = "ding2";
  // cout << myMax(ding1, ding2) << endl;
  // cout << myMax(1.0, 3.0) << endl;

  // 输出5050
  // 这样写的效率很高
  // 因为这种泛型迭代的方式是直接在编译阶段就生成好的
  // 也就是说 编译阶段就直接把Sum<100>::N 给算出来了
  // 代码执行阶段这儿就变成了 cout << 5050 << endl;
  cout << Sum<100>::N << endl;
  return 0;
}
