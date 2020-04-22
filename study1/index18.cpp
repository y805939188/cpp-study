#include "iostream"
using namespace std;

#include <vector>
#include <list>
#include <queue>
#include <stack>

#include <string>
#include <map>
#include <algorithm> // stl的算法模块
#include <numeric>
#include <functional>

/**
 * 容器适配器
 * stack堆栈 先进后出的容器 底层数据结构是使用的deque
 * 
 * queue队列 先进先出的容器 底层数据结构上会用的deque
 * 
 * priority_queue优先队列 一种特殊的队列 它能够在队列中进行排序（堆排序）底层实现结构是vector或者deque
 * 
 * 之所以叫容器适配器 因为他们都是适配器模式
 * 比如stack底层用的是容器中的deque结构 只是把这个结构给封装成适配于先进先出
 */

/**
 *  空间配置器 allocator
 *  空间配置器一般对于外层不可见 主要是用于描述内存或者硬盘空间如何分配
 * 
 *  有时候如果觉得stl对空间优化的不够好的话 就可以自己写空间配置器
 *  然后作为参数传给容器比如vector
 */

using std::allocator;

template <int T = 666>
class Ding {
  public:
    Ding() {
      cout << T << endl;
    }
};


int main(void) {

  Ding<> ding1;
  Ding<777> ding2;

  priority_queue<int> test1; // 默认是最大值优先
  priority_queue<int, vector<int>, less<int> > test2; // 最大值优先
  priority_queue<int, vector<int>, greater<int> > test3; // 最小值优先

  test1.push(2);
  test1.push(1);
  test1.push(8);
  test1.push(6);
  while(!test1.empty()) {
    cout << test1.top() << endl; // 8 6 2 1
    test1.pop();
  }



  int test4[5] = { 1,2,3,4,5 };
  vector<int, allocator<int> > v(test4, test4 + 5);
  for (unsigned int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }



  return 0;
}
