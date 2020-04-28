#include "iostream"
#include "string"
#include "vector"
// #include <functional>
using namespace std;

/**
 * 数组比较特殊
 * 1. 因为数组是不能被复制的
 * 2. 数组的名称是指向数组的第一个元素的指针
 */


// x就是一个指针 指向数组的第一个元素
// 一般都要把数组的长度也传进来
void print1(const int *x, size_t size) {
  // 这里lambda表达式报错是vscode的问题lint的问题 编译不影响
  for_each(x, x + size, [](int a)->void { cout << a << endl; } );
}

// 和 int *x 是一样的
void print2(const int x[], size_t size) {
  for_each(x, x + size, [](int a)->void { cout << a << endl; } );
}

// 这种和上面的一样 [] 里面的10会被编译器忽略掉
void print3(const int x[10], size_t size) {
  for_each(x, x + size, [](int a)->void { cout << a << endl; } );
}

// 所以其实以上三种效果是一样的
// 然后可以都加上const

// 还可以使用引用 必须加小括号 并且这个[9]里面的9必须得写
// 而且9必须和外边初始化时候的size对应上 否则报错
// 所以引用的方式不灵活 用得少
void print4(int (&x)[9]) {
  for_each(x, x + 9, [](int a)->void { cout << a << endl; } );
}

/**
 * 最常用的就是上面第一种传指针
 */


/**
 * 传多维数组
 * 
 */
// x 是一个指针 指向一个数组 这个数组是外层数组的第一个元素 每一行10个
// 相当于 int *x 指向数组的第一个元素 则 int (*x)[] 就表示指向的第一个元素也是数组
void print5(int (*x)[9], int row_size) {
  for_each(x, x + row_size, [](int *a) { // 注意这里就要变成 *a 了
    for_each(a, a + 9, [](int b)->void { cout << b; } );
    cout << endl;
  });
}

// 这种写法是最常见的标准库中的传一维数组的方法
void print6(const int *begin, const int *end) {
  while (begin != end) {
    cout << *begin++;
  }
  cout << endl;
}

int main(void) {
  int arr1[] = { 1,2,3,4,5,6,7,8,9 };
  print1(arr1, 9);
  print2(arr1, 9);
  print3(arr1, 9);
  print4(arr1);
  print6(arr1, arr1 + 9);

  cout << "-----------" << endl;
  int arr2[][9] = {
    { 1,2,3,4,5,6,7,8,9 },
    { 1,2,3,4,5,6,7,8,9 },
    { 1,2,3,4,5,6,7,8,9 }
  };
  print5(arr2, 3);

  char *str = "ddddd";
  char str2[] = "ddddd";

  return 0;
}
