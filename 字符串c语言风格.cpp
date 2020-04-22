#include "iostream"
#include "string"
using namespace std;

/**
 * 
 */

int main(void) {
  const char *str1 = "ding1";

  char str2[] = "ding2"; // c风格字符串
  char str3[] = { 'd', 'i', 'n', 'g', '3' }; // c++风格字符串
  char str4[] = { 'd', 'i', 'n', 'g', '4', '\0' }; // c语言要求结束必须显示生命 \0
  // 上面三种的变量名字都是指向数组第一个字符的指针
  char *p_str1 = str2;

  cout << *str1 << endl; // d
  
  while (*str1) {
    cout << *str1;
    str1++;
  }
  cout << endl;





  /**
   * c风格这种定义数组来声明字符串的方式不灵活
   * 必须通过c的标准库提供的方式操作
   */

  const char *str5 = "ding5";
  string str6("ding6");
  cout << "C:::" << strlen(str5) << endl; // strlen是c的标准库方法 在string.h文件中定义 但是c++中是 cstring
  cout << "C++:::" << str6.size() << endl;

  cout << strcmp(str5, str1) << endl; // str5 和 str1相等返回0 大于返回1 小于返回 -1

  char str7[] = "ding7";
  char str8[10];
  strcpy(str8, str7); // 把后面的字符串拷贝进第一个参数的数组中
  cout << str8 << endl;
  cout << strcat(str7, str8) << endl; // 字符串拼接 string类型的话可以直接+
  cout << strncpy(str8, str7, 6); // 从str7中拿6个放进str8 这个比较安全 防止黑客缓冲区溢出攻击

}
