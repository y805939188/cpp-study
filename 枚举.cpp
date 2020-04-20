#include "iostream"
using namespace std;

/**
 * 可以用作定义常量的类型
 */

enum REACT_MODE {
  REACT_STRUCT_MODE,
  REACT_CONCURRENT_MODE = 3,
  REACT_DEBUG_MODE,
};

int main(void) {

  REACT_MODE test;
  test = REACT_CONCURRENT_MODE;
  cout << test << endl; // 3
  cout << REACT_DEBUG_MODE << endl; // 4


  return 0;
}
