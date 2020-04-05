#include "iostream"
#include "./myclass/DingTest.h"
using namespace std;

int main(void) {
  DingTest ding1;
  ding1 = 666;

  cout << "这里的value是" << ding1._a << endl;

  DingTest ding2;
  ding2 = ding1;
  cout << "这里的下一个value是" << ding2._a << endl;

  ding2.printDingTest();


  return 0;
}
