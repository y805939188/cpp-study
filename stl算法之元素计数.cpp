#include "iostream"
#include "algorithm"
#include "vector"
#include "functional"
using namespace std;

/**
 * 
 */

bool isEven(int e) {
  return e % 2 == 0;
};

int main(void) {
  vector<int> ivec;
  for (int i = 0; i < 9; i++) ivec.push_back(i);

  for_each(ivec.begin(), ivec.end(), [](int a) -> void { cout << a << endl; });

  cout << count(ivec.begin(), ivec.end(), 6) << endl; // 1 表示从begin到end有多少个6

  cout << count_if(ivec.begin(), ivec.end(), isEven) << endl; // 1 表示从begin到end中能除开2的

  // greater 是预定义的 接收俩参数看param1是否 > param2 bind2nd是函数绑定 意思是把 8 绑定到 greater的参数中
  // cout << count_if(ivec.begin(), ivec.end(), bind2nd(greater<int>(), 8)) << endl;

  return 0;
}
