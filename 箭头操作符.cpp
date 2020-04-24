#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 箭头操作符 = 解引用操作符 + 点操作符
 * (*p) 这个是解引用
 * xxx.yyy 这个是点操作符
 * 所以
 * (*p).test()
 * p -> test()
 */

class Ding {
  public:
    void test() {
      cout << "test" << endl;
    }
};

int main(void) {
  Ding ding1;
  ding1.test();

  Ding *d1 = new Ding();
  (*d1).test();
  d1 -> test();

  int t = 666;
  int *p = &t;
  *p = 888;
  cout << t << endl; // 888

  string str;
  vector<string*> arr;
  while (cin >> str) {
    string *p_str = new string;
    *p_str = str;
    arr.push_back(p_str);
  }

  vector<string*>::iterator iter = arr.begin();
  while(iter != arr.end()) {
    cout << **iter << endl;
    iter++;
  }

  iter = arr.begin();
  while(iter != arr.end()) {
    delete *iter;
    iter++;
  }
  return 0;
}
