#include "iostream"
#include "string"
using namespace std;

/**
 * ~按位取反
 * << 按位左移
 * >> 按位右移
 * & 按位与
 * ^ 按位非
 * | 按位或
 */

int main(void) {
  unsigned char a = 1; // 00000001
  cout << (int)a << endl; // 1
  unsigned res = a << 1; // 00000010
  cout << (int)res << endl; // 2
  return 0;
}
