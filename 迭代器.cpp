#include "iostream"
#include "vector"
using namespace std;

/**
 * 标准库中的所有容器都有迭代器
 * 而下标只有少部分容器支持
 */ 

int main(void) {
  vector<int> test1(8, 6);

  vector<int>::iterator iter1 = test1.begin(); // begin返回一个迭代器 指向第一个元素

  *iter1 = 66;

  iter1++;

  *iter1 = 88;

  for (vector<int>::size_type i = 0; i < test1.size(); i++) {
    cout << test1[i] << endl; // 66 88 6 6 6 6 6 6
  }

  for (vector<int>::const_iterator ii = test1.begin(); ii != test1.end(); ii++) {
    cout << *ii << endl; // 66 88 6 6 6 6 6 6
  }




  return 0; 
}