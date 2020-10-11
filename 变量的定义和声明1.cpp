#include "iostream"
using namespace std;

int b = 0;

void test(int &p) { // 传的是地址
  cout << "2:: " << p << endl;
}

class Ding {
  public:
    Ding() {}
    Ding(const Ding & c) {
      cout << "拷贝构造" << endl;
    }
};
void test2(Ding *p) { // p是指针
  cout << "3:: " << &p << endl;
}

int main(void) {
  int a = 888;
  cout << "1:: " << &a << endl;
  test(a);

  Ding *d = new Ding();
  cout << "ding:: " << d << endl;
  test2(d);
  return 0;
}
