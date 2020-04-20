#include "iostream"
using namespace std;

/**
 * 一般系统自带的头文件使用<>
 * 自己写的头文件一般用 ""
 * 还可以写变量的声明
 */

extern double x; // .h 头文件可以用来声明变量
const int b = 999; // 头文件中只有常量可以初始化

/**
 * c++在编译之前会进行预编译 其实就是把引用的头文件粘贴复制到这个文件
 * 所以可能会出现重复引用头文件的情况
 * 
 * 所以可以使用头文件保护符
 * 
 * #ifndef _XXXX_XXX
 * #define _XXXX_XXX
 *
 * // ...这里写代码
 * 
 * #endif
 */

int main(void) {

 return 0; 
}