#include "iostream"
#include "string"
#include "vector"
#include "deque"
#include "algorithm"
using namespace std;

/**
 * 比vector更灵活 可在头尾插入
 */

int main(void) {
  deque<int> a;

  a.push_back(1);
  a.push_back(2);

  a.push_front(6);
  a.push_front(8);

  for (size_t i = 0; i < a.size(); i++) {
    cout << a[i] << endl;
  }

  a.pop_back();
  a.pop_front();

  deque<int>::iterator iter;
  for (iter = a.begin(); iter != a.end(); iter++) {
    // distance 可以计算当前迭代器和begin之间的偏移量
    size_t offset = distance(a.begin(), iter);
    cout << offset << *iter << endl;
  }
  std::string b("88");
  return 0;
}
