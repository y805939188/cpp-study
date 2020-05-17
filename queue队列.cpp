#include "iostream"
#include "queue"
#include "list"
using namespace std;

/**
 * 和stack对应 是队列 先进先出
 * 也是自适应容器 或者叫容器适配器
 * 使用deque或list配合
 * q.empty()
 * q.size()
 * q.front()
 * q.back()
 * q.pop()
 * q.push(item)
 * 
 * queue因为是先进先出
 * 所以要求对容器的两端都能进行操作
 * 而vector是向量
 * 向量只有一个方向
 * 所以不能使用vector去创建队列
 * 
 * 
 * 
 * 
 * 优先级队列 priority_queue
 * 也是自适应容器 或者叫适配器
 * 但是不能使用list 也就是说只能使用deque和vector
 * 最大值优先级队列、最小值优先级队列
 * pq.empty()
 * pq.size()
 * pq.top()
 * pq.pop()
 * pq.push(item)
 * 因为在优先级队列中要求对数据进行随机操作
 * 所以不能使用list
 * 
 */

int main(void) {

  queue<int, list<int>> a;
  queue<int, deque<int>> b;
  queue<int> c; // 默认是deque

  // push 是往队尾插入
  c.push(1);
  c.push(2);
  c.push(3);
  cout << c.size() << endl; // 3
  cout << c.front() << endl; // 1 看一看队首的数据
  cout << c.back() << endl; // 3 看一看队尾的数据
  c.pop(); // 在队首删除
  cout << c.front() << endl; // 2
  cout << c.empty() << endl; // 0 看是否队列是空



  // greater<int> 是谓词 加上这个就是最小级优先队列
  priority_queue<int, vector<int>, greater<int>> p1;
  priority_queue<int, deque<int>> p2;
  priority_queue<int> p3; // 默认是vector

  p3.push(2);
  p3.push(3);
  p3.push(1);
  cout << p3.top() << endl; // 3
  p3.pop();
  cout << p3.top() << endl; // 2 每次都删除最大的
  return 0;
}
