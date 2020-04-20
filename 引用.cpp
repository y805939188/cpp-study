#include "iostream"
using namespace std;

/**
 * 引用约等于变量的别名
 * 
 */

int main(void) {
  int a = 666;
  int &b = a;
  // int &c = 666; // 报错
  const int& d = 666; // 可以
  const int& e = d + 1; // const类型的引用可以初始化为同类型的别的值
  return 0;
}
