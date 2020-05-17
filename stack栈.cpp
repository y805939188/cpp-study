#include "iostream"
#include "stack"
#include "vector"
#include "deque"
#include "list"
using namespace std;

/**
 * 先进后出
 * 后进先出
 * 
 * s.empty()
 * s.size()
 * s.pop()
 * s.top()
 * s.push(item)
 */

int main(void) {

  /**
   * stack 叫自适应容器 也叫容器适配器
   * 它没法独立工作
   * 通常和list deque list一起配合使用
   * 
   */
  stack<int, deque<int>> a;
  stack<int, vector<int>> b;
  stack<int, list<int>> c;
  stack<int> d; // 默认使用deque

  d.push(1);
  d.push(2);
  d.push(3);
  int x = d.top(); // top是查看数据
  cout << x << endl; // 3
  d.pop(); // pop是删除栈顶的数据
  x = d.top();
  cout << x << endl; // 2
  cout << d.size() << endl; // 2
  cout << d.empty() << endl; // 0 检测是否为空
  return 0;
}
