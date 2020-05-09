#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 可以重载的大概有42个
 * 
 * 不可以重载的有4个:
 *  ::  .*
 *  .   ?:
 */

// 比如重载函数调用操作符
struct absInt {
  // 重载函数调用操作符
  int operator() (int val) {
    return val < 0 ? -val : val;
  }
};
int main(void) {
  int i = -42;
  absInt absObj; // 函数对象
  unsigned int ui = absObj(i);
  cout << ui << endl; // 42

  /**
   * stl中有大量操作容器的算法
   * 这些算法需要传递函数对象作为参数
   * 
   */
  return 0;
}
