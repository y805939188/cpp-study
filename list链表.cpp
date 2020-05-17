#include "iostream"
#include "string"
#include "list"

/**
 * 
 */

int main(void) {
  using namespace std;

  /**
   * 
   * 链表不能使用下标
   * 只能使用迭代器
   *  
   */

  list<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_front(6);
  a.push_front(8);

  a.insert(a.begin(), 666); // 在开头的前面插入666
  a.insert(a.end(), 6, 7); // 在end的后面插入6个8

  list<int>::iterator iter;
  for (iter = a.begin(); iter != a.end(); iter++) {
    cout << *iter << endl;
  };

  list<int> b;
  b.insert(b.begin(), a.begin(), a.end()); // 把a里的都插入到b中

  for (iter = b.begin(); iter != b.end(); iter++) {
    cout << *iter << endl;
  };

  list<int> c;
  c.push_front(1);
  c.push_front(2);
  c.push_front(3);
  iter = c.begin();
  iter++;
  c.erase(iter); // 删除list中的某一项
  c.reverse(); // 反转
  c.sort(); // 排序
  for (iter = c.begin(); iter != c.end(); iter++) {
    cout << *iter << endl; // 1 3
  };

  return 0;
}
