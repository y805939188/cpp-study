#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 第一个参数表示个数 也就是需要有多少个参数
 * 第二个表示 每一个参数 字符串数组 每一个选项是一个字符串
 */

// ./output/处理命令行选项 ding1 ding2 ding3
int main(int argc, char **argv /** 或写成 char* argc[] 也可以 */) {

  char a[] = "666";
  char b[] = { 'a', 'b' };
  char d[][4] = { "888" };
  char* e = "666";
  char* f[] = { "666", "888" }; // f先跟右边结合 表示f是一个数组 数组中每项都是个指针
  char _g = '6';
  // char* __g = &_g;
  char* __g = "88888";
  char** g = &__g; // ((char*)*) g 表示有个指针 指向了char类型的指针 就是g

  cout << argc << endl; // 4
  cout << argv[0] << endl; // 0 不是命令行输入的参数 而表示c++的执行文件
  cout << argv[1] << endl; // ding1
  cout << argv[2] << endl; // ding2
  cout << argv[3] << endl; // ding3
  return 0;
}
