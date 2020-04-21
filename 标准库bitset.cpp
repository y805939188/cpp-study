#include "iostream"
#include "bitset"
#include "string"
using namespace std;

/**
 * 
 */ 

int main(void) {
  bitset<32> a; // a可以放32个二进制位 也就是32位的二进制 默认全是0
  cout << a << endl; // 00000000000000000000000000000000

  bitset<16> b(0xffff); // 1111 1111 1111 1111 一个16进制对应4个2进制
  cout << b << endl;

  bitset<32> c(0xffff); // 0000 0000 0000 0000 1111 1111 1111 1111
  cout << c << endl;

  bitset<32> d(156); // 0000 0000 0000 0000 0000 0000 1001 1100
  cout << d << endl;

  string str("00000000000000000000000010011100");
  bitset<32> e(str, 5, 4); // 从第5位开始 拿出4个来初始化成32位二进制
  bitset<32> f(str, str.size() - 6); // 把最后面6个拿出来初始化
  cout << e << endl;

  bool is_set = e.any(); // 是否至少有一位为1
  bool is_not_set = e.none(); // 是否全是0
  size_t bite_set = a.count(); // a里有几个1
  cout << bite_set << endl; // 0
  cout << a.size() << endl; // 32

  a[31] = 1; // 10000000000000000000000000000000
  cout << a << endl;
  a.set(30); // set是把某一位变成1
  cout << a << endl; // 11000000000000000000000000000000
  a.set(); // 把a所有的都set为1
  a.reset(); // 再全都变回0
  a.flip(); // 反转
  a.flip(31); // 反转某一位

  unsigned long g = a.to_ulong(); // 转成10进制
  cout << g << endl; // 2147483647



  /**
   * 位运算 
   */
  bitset<8> ding1(string("00001111"));
  cout << ding1 << endl; // 00001111
  bitset<8> ding2(string("10000001"));
  cout << ding2 << endl;

  cout << (ding1 & ding2) << endl; // 00000001 位与
  cout << (ding1 | ding2) << endl; // 10001111 位或
  cout << (ding1 ^ ding2) << endl; // 10001110 位异或


  return 0; 
}