#include "iostream"
#include "string"
#include "set"
using namespace std;

/**
 * set和multiset是集合 也是非顺序容器
 * 也是用红黑树实现的
 * insert
 * count和find
 * erase
 * 
 * 增删查的速度都很快
 * 
 * 就是插入的时候比list啥的稍微慢一丢丢
 */

int main(void) {

  set<int> a;
  multiset<int> b;

  /**
   * 会自动排序
   */
  a.insert(66);
  a.insert(88);
  a.insert(11);
  a.insert(77);
  set<int>::const_iterator iter1 = a.begin();
  while (iter1 != a.end()) {
    cout << *iter1 << endl;
    iter1++;
  }
  // 打印 11 66 77 88

  b.insert(a.begin(), a.end()); // 把a的数据全部插入到b中
  b.insert(88);
  b.insert(77);
  b.insert(77);
  cout << b.count(77) << endl; // 3 可以查找有多少个该重复的元素


  // 查找
  set<int> c;
  c.insert(6);
  c.insert(8);

  set<int>::iterator iter_c = c.find(6); // 返回一个迭代器
  if (iter_c != c.end()) {
    cout << "找到了" << endl;
  }


  // 删除
  set<int> d;
  d.insert(6);
  d.insert(6);
  d.insert(7);
  d.insert(8);
  d.erase(6); // 会把俩6都删掉
  
  d.clear(); // 直接清空

  return 0;
}
