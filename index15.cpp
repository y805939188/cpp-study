#include "iostream"
using namespace std;

#include <vector>
#include <list>
#include <queue>
#include <stack>

#include <string>
#include <map>
#include <algorithm> // stl的算法模块

/**
 * 仿函数 functor
 * 仿函数一般不会单独使用 主要是为了配合stl算法使用
 * 
 * 仿函数可以让stl算法更好地复用
 * 
 * 一般复用函数 可以使用函数指针
 * 但是这里函数指针不能满足对stl抽象的要求
 * 
 * 本质就是一个类 重载了operator() 创建了一个行为类似函数的对象
 */


bool Sort(int a, int b) {
  return a < b;
}

void MyPrint(int a) {
  cout << a << endl;
}

template <class T>
bool Sort2(T const& a, T const& b) { // 可以优化成const引用
  return a < b;
}

template <class T>
void MyPrint2(T a) {
  cout << a << endl;
}

struct Sort3 {
  bool operator() (int a, int b) {
    return a > b;
  };
};

struct MyPrint3 {
  void operator() (int a) {
    cout << a << endl;
  };
};

template <class T>
struct Sort4 {
  bool operator() (T a, T b) {
    return a > b;
  };
};

template <class T>
struct MyPrint4 {
  void operator() (T a) {
    cout << a << endl;
  };
};


int main(void) {
  int arr1[] = { 6,3,8,5,1,9,6,7,5 };
  sort(arr1, arr1 + 9, Sort);
  for_each(arr1, arr1 + 9, MyPrint);
  cout << endl;

  int arr2[] = { 6,3,8,5,1,9,6,7,5 };
  sort(arr2, arr2 + 9, Sort2<int>);
  for_each(arr2, arr2 + 9, MyPrint2<int>);
  cout << endl;

  int arr3[] = { 6,3,8,5,1,9,6,7,5 };
  sort(arr3, arr3 + 9, Sort3());
  for_each(arr3, arr3 + 9, MyPrint3());
  cout << endl;

  int arr4[] = { 6,3,8,5,1,9,6,7,5 };
  sort(arr4, arr4 + 9, Sort4<int>());
  for_each(arr4, arr4 + 9, MyPrint4<int>());
  cout << endl;

  return 0;
}
