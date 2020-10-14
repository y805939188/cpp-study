#include "iostream"
#include "string"
#include "vector"
#include "map"
using namespace std;

/**
 * map映射与nultimap多映射 也是非顺序容器
 * 
 * c++中用 红黑树 存储key val
 * 
 * insert 4种方法
 * count和find
 * erase 3种方法
 */

int main(void) {

  map<int, string> m1;
  multimap<int, string> m2;

  m1.insert(map<int, string>::value_type(1, "1"));
  m1.insert(map<int, string>::value_type(2, "2"));
  m1.insert(map<int, string>::value_type(3, "3"));

  m1.insert(make_pair(6, "6"));
  m1.insert(pair<int, string>(8, "8"));

  m1[666] = "666";
  m1[888] = "888";

  cout << m1.size() << endl; // 7

  map<int, string>::const_iterator iter;
  for (iter = m1.begin(); iter != m1.end(); iter++)  {
    cout << "key : " << iter -> first << "  ";
    cout << "value : " << iter -> second.c_str();
    cout << endl;
  }

  m2.insert(multimap<int, string>::value_type(1, "1"));
  m2.insert(make_pair(2, "2"));
  m2.insert(make_pair(2, "22222")); // 可添加重复的
  m2.insert(pair<int, string>(3, "3"));
  m2.insert(pair<int, string>(3, "33333")); // 可添加重复的

  cout << m2.size() << endl; // 5
  multimap<int, string>::const_iterator iter2;
  for (iter2 = m2.begin(); iter2 != m2.end(); iter2++)  {
    cout << "key : " << iter2 -> first << "  ";
    cout << "value : " << iter2 -> second.c_str();
    cout << endl;
  }
  // 他不能直接 m2[xxx] = yyy
  cout << m2.count(2) << endl; // 2 可以看到m2中有几个2

  multimap<int, string>::const_iterator i;
  i = m2.find(3);
  if (i != m2.end()) {
    // 说明找到了
  } else {
    // 说明没找到
  };

  // 对于普通的map来说 可以直接中括号查找
  cout << m1[1] << endl;


  // 对于删除 有三种方法
  if (m1.erase(2) > 0) {
    // 如果删除key为2的成功的话 返回大于0
    cout << "删除成功" << endl;
  };

  multimap<int, string>::iterator fi = m2.find(3);
  if (fi != m2.end()) {
    // end是一个特殊的标志
    m2.erase(fi);
  };

  // 把multimap中的最上面的key为3的一直到最下面的key为3的都删掉
  m2.erase(m2.lower_bound(3), m2.upper_bound(3));

  cout << "--------test copy--------" << endl;
  map<char, int> m111;
  m111['a']++;
  cout << m111['a'] << endl; // 1
  map<char, int> m222;
  m222 = m111;
  cout << m222['a'] << endl; // 1
  m222['a']--;
  cout << m222['a'] << endl; // 0
  cout << m111['a'] << endl; // 1

  cout << m222.count('a') << endl; // 1
  cout << m222.count('b') << endl; // 0

  return 0;
}
