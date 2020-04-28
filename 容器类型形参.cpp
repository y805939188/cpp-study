#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
 */

// 非引用形参
// 由于他就是copy 所以不太好
void print(vector<double> v) {
  vector<double>::iterator iter = v.begin();
  while(iter != v.end()) {
    cout << *iter << endl;
    iter++;
  }
} 

//
void print2(vector<double>& v) {
  vector<double>::iterator iter = v.begin();
  while(iter != v.end()) {
    cout << *iter++ << endl;
  }
}

void print3(vector<double>::const_iterator begin, vector<double>::const_iterator end) {
  while(begin != end) {
    cout << *begin++ << endl;
  }
}



int main(void) {
  vector<double> v1;
  v1.push_back(1.0);
  v1.push_back(1.1);
  v1.push_back(1.2);
  // 相当于把v1直接复制给print的参数
  // 如果v1超级大 那就又费时又占地方
  print(v1);
  // 引用相当于直接把v1传进去
  print2(v1);


  /**
   * 其实c++中
   * 对于容器最好传递迭代器
   * 这种是最常见的方法
   */
  print3(v1.begin(), v1.end());

  return 0;
}
