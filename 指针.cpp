#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 在c中主要用来操作数组和字符数组(字符串)
 * 不过c++标准库中有string和vector来替代
 */

/**
 * 指针在声明的时候可以不初始化
 * 但是引用必须要有初始化
 * 并且引用声明之后 不允许再改变引用
 */

int main(void) {
  string a("ding1");
  string *p_a = &a;
  cout << p_a << endl; // 地址

  vector<int> *b;

  int *p = 0; // 等于0的时候表示不指向任何对象
  int *p_p = NULL; // 可以 NULL 是一个宏定义 大部分情况下就是0

  double num1 = 3.14;
  int num2 = 666;
  void *p_niubi = &num1; // 万能指针 可以指向任何一种类型的对象
  p_niubi = &num2;
  // 万能指针比较危险 因为所指向的对象类型是不确定的 所以仅限在一些特定情况下使用

  int n = 1;
  int *p_n = &n;
  *p_n = *p_n + 5;
  cout << *p_n << endl; // 6

  int **p_n_n = &p_n; // 指针的指针



  int i_arr[] = { 1,2,3,4,5,6,7,8 };
  int *p_i_arr = i_arr; // 指向第一个 可以认为数组的变量就是一个指针
  cout << "是否相等" << (p_i_arr == i_arr) << endl;
  cout << "可以像使用数组一样使用数组的指针" << p_i_arr[1] << endl; // 可以认为指针就是数组的迭代器
  p_i_arr = &i_arr[6]; // 让这个指针指向i_arr的第6位
  int *p_i_arr2 = p_i_arr + 1; // 指向p_i_arr后面的一个

  ptrdiff_t distance = p_i_arr2 - p_i_arr; // 两个指针中的距离
  cout << distance << endl; // 1

  int result = *(i_arr + 5); // i_arr 也是个指针 所以相当于把指针后移5位之后取值
  cout << result << endl; // 6


  vector<int> i_ve;
  i_ve.push_back(1);
  i_ve.push_back(2);
  i_ve.push_back(3);
  i_ve.push_back(4);

  vector<int>::iterator iter = i_ve.begin();
  cout << *iter << endl;

  







  /**
   * const限定符
   * 特殊的指针
   */
  double p0 = 3.1415926;
  const double p1 = 3.1415926;
  // double *p_p1 = &p1; // 会报错 常亮必须用常亮指针
  const double *p_p1 = &p1;
  p_p1 = &p0; // 常量指针可以指向普通的对象

  /**
   * const xxxx *yyyy = zzzz;
   * 表示他是一个指针 指针指向一个常量 指针本身可以改变 
   */

  double *const p_p2 = &p0;
  double p3 = 6.28;
  // p_p2 = &p3; // 会报错
  
  /**
   * xxxx *const yyyy = zzzz;
   * 表示他是一个常量 这个常量是个指针 由于该指针是常量所以指针本身不能被修改 
   */


  double const p6 = 3.14;

  double const * const p_p6 = &p6;
  const double * const p_p7 = &p6;
  /**
   * xxxx const * const yyyy = &zzzz;
   * const xxxx * const yyyy = &zzzz;
   * 以上这两种形式一样 是把上面的指针常量和常量指针给综合了一下
   * 表示这个指针自己本身既是一个常量 他也指向一个常量
   */





  /**
   * 常量指针常用于函数传参
   * void xxx(const int *p) {}
   * 用于防止函数内部修改参数
   */



  return 0; 
}