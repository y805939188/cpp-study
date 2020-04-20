#include "iostream"
// #include <string> // 不写也行 因为包含在std中了
#include<cctype> // ctype.h 是c语言的引入头文件的写法 c++ 中就把.h去掉 前面加个c
using namespace std;

/**
 * 
 */ 

int main(void) {

  char name1[] = "ding1"; // c语言中定义字符串的方法

  // 4种初始化方法
  string name2;
  string name3("ding2");
  string name4(name3);
  string name5(10, 'd');

  // 这种一般不用 因为效率低 内部把 = 重载
  string name6 = "ding3";

  cout << name3.size() << endl;

  // 不能用int 专门用这么一个类型表示size
  // 因为首先size是无符号 并且有可能会超级大 所以有可能int满足不了
  // 所以专门设计了一个类型
  string::size_type size1 = name3.size();

  name3.empty(); // 判断字符串是否为空

  cout << name3 + name4 << endl; // ding2ding2

  // string name7 = "ding6" + "ding8"; // 报错 c++不允许
  string name8 = name3 + "ding9"; // 这样可以
  // string name9 = "ding10" + "ding11" + name3; // 这样也会报错 右侧不能出现连续两个字面量


  cout << "-----------------------------" << endl;
  /**
   * string 是stl标准库中的 一种字符容器
   * 可以使用下标操作 改变字符串中的字符
   */

  string name9("dingye");
  cout << name9[3] << endl;

  for (string::size_type i = 0; i < name9.size() ; i++) {
    cout << name9[i] << ' ';
  }
  cout << endl;

  for (string::size_type i = 0; i < name9.size() ; i++) {
    name9[i] = '*';
    cout << name9[i] << ' ';
  }
  cout << endl;

  string name10("1ding ye, niubi");
  cout << ispunct(name10[8]) << endl; // ispunct判断是否是标点符号
  cout << isalnum(0) << endl; // 是不是字母或者数字
  // isalpha // 是不是字母
  // iscntrl // 是不是控制字符
  // isdigit // 是不是数组
  // islower // 是不是小写字母
  // isspace // 是不是空格
  // isupper // 是不是大写字母
  // tolower // 转成小写
  // toupper // 转成大写

  for (string::size_type i = 0; i < name10.size(); i++) {
    name10[i] = toupper(name10[i]);
    cout << name10[i] << ' ';
  }


 return 0; 
}