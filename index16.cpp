#include "iostream"
using namespace std;

#include <vector>
#include <list>
#include <queue>
#include <stack>

#include <string>
#include <map>
#include <algorithm> // stl的算法模块
#include <numeric>
#include <functional>

/**
 * algorithm 算法
 * 大致分为4类 包含于 <algorithm> <numeric> <functional>
 * 
 * 1. 非可变序列算法 不影响容器本身
 * 2. 可变序列算法 直接影响容器本身
 * 3. 排序算法 对序列进行排序和合并 搜索 集合等操作的算法
 * 4. 数值算法 对容器内容进行数值计算
 * 
 */


int main(void) {
  int arr1[] = { 1, 2, 3, 4, 5 };
  int arr2[] = { 10, 20, 30, 40, 50 };
  int result[5];
  // 第三个参数可以传第二个list 并且第二个list会默认走和arr1一样的长度
  // 然后把第5个参数处理完的结果放进result
  transform(arr1, arr1 + 5, arr2, result, std::plus<int>()); // std::plus就是接收俩参数然后相加
  for_each(result, result + 5, [](int a) -> void { cout << a << endl; }); // lambda表达式 相当于一个匿名函数
  // lambda表达式 ](int a) { } 返回值是void或函数体中只有一处return(编译器可以自动推断出返回类型)的时候可以不写
  // 前面那个 [] 中括号中 可以传入一些外部的变量 然后在函数体内部使用


  return 0;
}
