#include "iostream"
#include "string"
#include "vector"
#include "fstream"
// #include "stringstream"

using namespace std;

/**
 * iostream 就是输入输出流
 * iostream继承了 ostream和istream
 * 然后ostream下还有ofstream(文件输出流)以及ostringstream(字符串输出流)两个子类
 * istream下还有istringstream(字符串输入流)以及ifstream(文件输入流)两个子类
 * iostream下有stringstream(字符串输入输出流)和fstream(文件输入输出流)两个子类
 * 
 * 
 * 输入输出流对象 都不可以复制
 * 所以不能放进stl标准库比如vector等容器里面
 * 因为容器中的东西都可以复制
 */

// 因为函数返回的时候都是返回的复制 所以这里的返回类型必须用引用才不复制
ofstream& xxx(ofstream& of) {
  return of;
};

int main(void) {

  std::fstream fs;
  // std::stringstream ss;

  return 0;
}
