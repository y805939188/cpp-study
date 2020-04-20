#include "iostream"
using namespace std;

int a = 1; // 变量的定义
extern int b; // 变量的声明
// extern int c = 666; // 如果已经初始化了 就变成了变量的定义了

/**
 * a会直接初始化并分配内存空间
 * b是当当前文件(模块)中没有b 但是别的文件(模块)中有b这个变量的时候
 * 想在当前文件(模块)中使用的情况下 可以使用extern作为变量声明 
 * 
 */

// 如果把两个文件一起编译 就会有b的输出
int main(void) {
  cout << ++b << endl;
  return 0;
}
