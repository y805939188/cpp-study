#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
 */

int num() {
  // 静态的局部变量的生命周期可以横跨到main函数结束
  static int a = 0; // 会检测是否之前已经存在静态的a 如果有的话就复用并且不再初始化
  a++;
  return a;
}

int main(void) {
  cout << num() << endl; // 1
  cout << num() << endl; // 2
  cout << num() << endl; // 3


  return 0;
}
