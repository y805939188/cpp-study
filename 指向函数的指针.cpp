#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
 */

// 不加括号 表示pf是一个函数 这个函数的返回值是一个bool类型的指针
// bool* pf (const string &, const string &);
// 加了括号 表示pf是一个指针 该指针指向一个返回bool类型的函数
bool (*pf) (const string &, const string &);

bool compare(const string &s1, const string &s2) {
  return s1.size() == s2.size();
}

void useBigger(
  const string s1,
  const string s2,
  bool (*pf2) (const string &, const string &)
) {}

// ff 是一个函数 有一个形参x 返回结果是一个函数指针 int(*)(int *, int)
int (*ff(int x))(int *, int) {};
// 上边这个可以简化
typedef int (*ff_type)(int *, int);
// 然后
ff_type ff2(int x) {};

int main(void) {
  pf = &compare;

  cout << pf("ding1", "ding2") << endl; // 1
  cout << (*pf)("ding2", "ding1") << endl; // 1 pf也是个指针 也可以用*解除引用

  typedef bool (*pf2) (const string &, const string &);
  pf2 p1; // 可以用typedef定义一个别名 就可以很方便地定义同样类型的指针
  pf2 p2;
  p1 = &compare;
  cout << p1("a", "b") << endl; // 1

  useBigger("a", "b", p1);
  useBigger("a", "b", compare); // 函数的名称其实就是一个指向函数的指针 函数不可以作为参数传递 但是函数指针可以

  return 0;
}
