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
 * 迭代器
 * 是一种智能指针 用于访问顺序容器和关联容器中的元素
 * 相当于容器和操作容器的算法之间的中介
 * 
 * 迭代器主要按照定义方式分成下面四种
 *  1. 正向迭代器 iterator
 *  2. 常量正向迭代器 const_iterator
 *  3. 反向迭代器 reverse_iterator 
 *  4. 常亮反向迭代器 const_reverse_iterator
 * 
 * vector 随机访问
 * deque 随机访问
 * list 双向访问
 * set/multiset 双向访问
 * map/multimap 双向访问
 * stack 不支持迭代器
 * queue 不支持迭代器
 * priority_queue 不支持迭代器
 * 上面三个对输入和输出有比较严格的限制
 */


int main(void) {
  list<int> v1;
  v1.push_back(6);
  v1.push_back(8);
  v1.push_front(8);
  v1.push_front(6);

  list<int>::const_iterator it;
  for (it = v1.begin(); it != v1.end(); it++) {
    // *it += 1; // 这里由于是 const_iterator 常亮迭代器 所以不能修改内容
    cout << *it << " ";
  }
  cout << endl;
  cout << v1.front() << endl;
  v1.pop_back();
  v1.pop_front();
  for (it = v1.begin(); it != v1.end(); it++) {
    // 如果是反向的reverse迭代器的话 就从 v1.rbegin 开始 到v1.rend结束
    cout << *it << " ";
  }
  cout << endl;


  return 0;
}
