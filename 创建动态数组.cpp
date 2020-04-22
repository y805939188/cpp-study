#include "iostream"
#include "string"
using namespace std;

/**
 * 
 */

int main(void) {
  int a[10]; // 静态数组 在栈上创建
  int *p_a = new int[10]; // 动态创建
  delete[] p_a; // 一定要释放 对于数组一定要加 []

  string *p_str1 = new string[10]; // 会调用默认构造函数初始化
  int *p_a2 = new int[10]; // 没有初始化
  int *p_a3 = new int[10](); // 会初始化 内部都初始化成0 动态数组只能初始化成0
  cout << p_a3 + 2 << endl; // 地址
  cout << *(p_a3 + 2) << endl; // 0
  *(p_a3 + 2) = 66;
  cout << *(p_a3 + 2) << endl; // 66


  return 0;
}
