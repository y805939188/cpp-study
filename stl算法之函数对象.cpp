#include "iostream"
#include "set"
#include "algorithm"
using namespace std;

/**
 * 函数对象可以有自己的状态
 * 速度也比普通函数快
 */

class Print {
  public:
    void operator() (int ele) const {
      cout << ele << endl;
    };
};

template <class T>
class Print2 {
  public:
    void operator() (T ele) const {
      cout << ele << endl;
    };
};


int main(void) {


  /**
   * 函数对象可以和set之类的一块儿用
   * 也可以和算法一块儿用
   */
  // 底层是自动排序的红黑树
  // set的第二个参数可以表示如何排序
  // 这个控制如何排序的就是函数对象
  set<int, greater<int>> a;
  set<int, less<int>> b; // set<int> 默认就是这个

  a.insert(9);
  a.insert(7);
  a.insert(66);
  a.insert(88);

  for_each(a.begin(), a.end(), [](int a) -> void { cout << a << endl; });
  cout << "-----------" << endl;
  for_each(a.begin(), a.end(), Print());
  cout << "-----------" << endl;
  for_each(a.begin(), a.end(), Print2<int>());



  return 0;
}
