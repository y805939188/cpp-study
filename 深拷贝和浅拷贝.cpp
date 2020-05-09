#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
 */

class Test {
  public:
    int num;
    char* str;
    Test(int initNum, char* initStr) {
      this -> num = initNum;
      this -> str = new char[1024];
      strcpy(str, initStr);
    }
    Test(Test& obj) {
      // 拷贝构造可以用来做深拷贝 不然c++自己写的编译器会做浅复制
      this -> num = obj.num;
      this -> str = new char[1024];
      if (str != 0) strcpy(this -> str, obj.str);
    };
};

int main(void) {

  return 0;
}
