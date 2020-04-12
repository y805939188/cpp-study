#include "iostream"
using namespace std;

/** STL 标准模版库 */
/** 第一部分 容器 */
/**
 * 序列式容器
 *  vector list deque是序列式容器
 *  stack queue priority_queue 是容器适配器
 * 关联式容器
 *  set multiset map multimap
 */

#include <vector>
#include <list>
#include <queue>
#include <stack>

#include <string>
#include <map>
#include <algorithm> // for_each 需要它

struct Display {
  // 重载一个()括号 这里等效于一个函数
  // 比如正常Display xxx是创建一个实例
  // 这里可以 Display(int) 
  void operator()(int i) { // 仿函数
    cout << i << " ";
  }
  void operator()(pair<string, double> info) { // 仿函数
    cout << info.first << "  :  " << info.second << endl;
  }
};

int main(void) {
  int iArr[] = { 1,2,3,4,5 };
  vector<int> iVector(iArr, iArr + 4);

  list<int> iList(iArr, iArr + 4);

  deque<int> iDeque(iArr, iArr + 4);

  for_each(iVector.begin(), iVector.end(), Display());
  cout << endl;
  for_each(iList.begin(), iList.end(), Display());
  cout << endl;
  for_each(iDeque.begin(), iDeque.end(), Display());
  cout << endl;

  queue<int> iQueue(iDeque); // 队列 先进先出
  stack<int> iStack(iDeque); // 栈 先进后出
  priority_queue<int> iPriorityQueue(iArr, iArr + 4); // 优先队列 按优先级出

  while (!iQueue.empty()) { // 1 2 3 4
    cout << iQueue.front() << " "; // 把头部的读取出来
    iQueue.pop(); // 从头部干掉
  };
  cout << endl;

  while (!iStack.empty()) { // 4 3 2 1
    cout << iStack.top() << " "; // 把头部的读取出来
    iStack.pop(); // 从头部干掉
  };
  cout << endl;

  while (!iPriorityQueue.empty()) { // 4 3 2 1
    cout << iPriorityQueue.top() << " "; // 把头部的读取出来
    iPriorityQueue.pop(); // 从头部干掉
  };
  cout << endl;







  map<string, double> studentSocres;
  studentSocres["ding1"] = 100;
  studentSocres["ding2"] = 99.9;
  // pair 定义在 #include <utility> 头文件中 pair可以将2个数据组合成一组数据
  // 比如当一个函数需要返回2个数据的时候 可以选择pair
  // pair的实现是一个结构体 主要的两个成员变量是first second
  // 因为是使用struct不是class 所以可以直接使用pair的成员变量

  /**
   * 
   * pair<T1, T2> p1;            //创建一个空的pair对象（使用默认构造），它的两个元素分别是T1和T2类型，采用值初始化。
   * pair<T1, T2> p1(v1, v2);    //创建一个pair对象，它的两个元素分别是T1和T2类型，其中first成员初始化为v1，second成员初始化为v2。
   * make_pair(v1, v2);          // 以v1和v2的值创建一个新的pair对象，其元素类型分别是v1和v2的类型。
   * p1 < p2;                    // 两个pair对象间的小于运算，其定义遵循字典次序：如 p1.first < p2.first 或者 !(p2.first < p1.first) && (p1.second < p2.second) 则返回true。
   * p1 == p2；                  // 如果两个对象的first和second依次相等，则这两个对象相等；该运算使用元素的==操作符。
   * p1.first;                   // 返回对象p1中名为first的公有数据成员
   * p1.second;                 // 返回对象p1中名为second的公有数据成员
   * 
   */
  studentSocres.insert(pair<string, double>("ding3", 98.8));
  studentSocres.insert(pair<string, double>("ding4", 66.6));

  studentSocres.insert(map<string, double>::value_type("ding5", 88.8));

  // Display 加上 () 表示一个函数 因为做了重载
  for_each(studentSocres.begin(), studentSocres.end(), Display());

  map<string, double>::iterator iter;
  iter = studentSocres.find("ding3");
  if (iter != studentSocres.end()) {
    cout << "分数是::" << iter -> second << endl;
  } else {
    cout << "没有这个值" << endl;
  }





  return 0;
}
