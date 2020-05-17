#include "iostream"
#include "string"
#include "vector"
#include "list"
using namespace std;

/**
 * 顺序容器
 *  vector
 *  list
 *  deque
 * 顺序容器适配器
 *  stack
 *  queue
 *  priority_queue
 */

class Test {
  public:
    int _n;
    Test(int num) {
      _n = num;
    };
};

int main(void) {
  vector<int> a; // 无参数的初始化
  a.push_back(1);
  vector<int> b(a); // 有参数的初始化
  vector<int> c(b.begin(), b.end()); // 还可以用迭代器初始化 这样可以控制长度
  vector<int>::iterator iter = c.begin() + (c.size() / 2); // 迭代器查找中间位置

  char* d[] = { "abc", "defg" };
  cout << sizeof(d) << endl; // 16 d这个数组中有俩char类型指针 
  cout << sizeof(char*) << endl; // 8 每个char类型的指针是8位
  size_t size = sizeof(d) / sizeof(char*);

  list<string> words(d, d + size); // 还可以使用指针去初始化

  list<string> strs(64); // 初始化了一个string类型的链表 链表有64位
  list<string> strs2(88, "ding"); // 初始化一个88位的string类型的链表 初始值是ding

  vector<Test> myList(6, 8); // 可以这样用自定义的class以及构造函数初始化
  cout << myList[0]._n << endl; // 8

  vector< vector<string> > niubi; // 可以容器嵌套容器 最后的箭头一定要隔开 否则会被认为成是 >> 符号
  return 0;
}
