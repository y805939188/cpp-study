#include "iostream"
using namespace std;

// 可以使用内联函数 在有些编译器比如 visual studio需要开启该功能才行

inline int MaxValue(int a, int b) {
  return a > b ? a : b;
}

// 循环版 斐波那契数列
int Fib1(int n) {
  int n0 = 0;
  int n1 = 1;
  int temp;

  for (unsigned int i = 2; i < n; i++) {
    temp = n0 + n1;
    n0 = n1;
    n1 = temp + n1;
  }
  return n1;
}

// 尾递归版斐波那契数列
// 尾递归之所以效率比普通递归高
// 是因为像上面那个递归 虽然也是最后return的递归
// 但是上面那种最后return的是一个表达式
// 编译器对于那种表达式中的函数执行 会重新生成他们的调用栈
// 但是对于这种直接return的就是一个函数的情况
// 编译器会对其做优化 省略好多调用栈
int Fib2(int n, int n0, int n1) {
  if (n == 0) return n0;
  // if (n == 1) return n1;
  return Fib2(n - 1, n1, n1 + n0);
}
/**
 * 因为尾递归是当前函数最后一个动作
 * 所以当前函数帧上的局部变量（全局变量保存在堆中）等大部分的东西都不需要了保存了
 * 所以当前的函数帧经过适当的更动以后可以直接当作被尾调用的函数的帧使用
 * 因此整个过程只要使用一个栈帧 在函数栈中不用新开辟栈空间
 * 省去了向上返回->计算所用的时间 这样的话整个的计算过程就变成了线性的时间复杂度
 */

// 动态规划
// 以空间换时间
// 将已经算出来的值存起来
int arr[1000];
int Fib3(int n) {
  arr[0] = 0;
  arr[1] = 1;
  for (int i = 2; i < n; i++) {
    if (arr[i] == 0) {
      arr[i] = arr[i - 1] + arr[i - 2];
    }
  }
  return arr[n - 1] + arr[n - 2];
}

int main(void) {

  int a = 3;
  int b = 4;

  cout << "牛逼1" << ';' << Fib1(5) << endl;
  cout << "牛逼2" << ';' << Fib2(10, 0, 1) << endl;
  cout << "牛逼3" << ';' << Fib3(10) << endl;

  // 内联函数其实就是空间换时间的一种优化策略
  // 一个普通函数在初始化时候 会进行一堆的压栈操作 还有一堆出栈操作
  // 而内联函数 就相当于直接把函数体给拷贝过来了 所以省去了压栈等过程
  // 但是会在每一个调用内联函数的地方 都隐式地把函数体拷贝一遍
  // 所以是空间换时间的方法
  cout << MaxValue(a, b) << endl;
  // 有些函数不适合内联
  // 有些特别复杂的或者有些递归之类的 就不适合内联 编译器会自动关掉它的内联

  return 0;
}
