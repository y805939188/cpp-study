#include "iostream"
#include "string"
#include "vector"
#include "memory" // 这个库里头有auto_ptr智能指针
using namespace std;

/**
 * 常规的指针类 是浅复制 两个指针指向同一个对象
 * delete一个之后可能会导致另外一个指针变成野指针
 * 
 * 智能指针是计数类 对每个指针进行引用计数
 * 
 * 值类型是深复制 但是会大量占用内存
 */

class Test {
  public:
    int* num;
    Test(int* n): num(n) {};
    int get_num() {
      return *(this -> num);
    }
};

// 智能指针 也叫做计数类
class U_ptr {
  friend class Test2;
  private:
    int* ip;
    size_t use; // 计数
    U_ptr(int* p): ip(p), use(1){};
    ~U_ptr() { delete ip; }
};

class Test2 {
  public:
    U_ptr* num;
    Test2(int* n): num(new U_ptr(n)) {};
    Test2(const Test2 &orig): num(orig.num) { ++(num -> use); };
    ~Test2() {
      if (--(num -> use) == 0) {
        delete num;
      }
    }
    Test2& operator=(const Test2&);

    int* get_num() {
      return num -> ip;
    }
};
Test2& Test2::operator =(const Test2 &rhs) {
  // 一般都这么写 这样写的话 就允许把自己复制给自己
  ++(rhs.num -> use);
  if (--(num -> use) == 0) delete num;

  num = rhs.num;
  return *this;
}





// 智能指针
void demo1() {
  int* p = new int(66);
  auto_ptr<int> a1(p);
  auto_ptr<double> a2(new double);
  *a2 = 88.88;
  cout << *a1 << endl; // 66
  cout << *a2 << endl; // 88.88
};

int main(void) {
  int* p1 = new int(66);
  Test test1(p1);
  delete p1; // 由于Test还有个num指针也指向66 所以num变成野指针(悬垂指针)了就
  // cout << test1.get_num() << endl;




  /**
   * c++ 中提供好的智能指针
   * std::auto_ptr(标准模板库中的智能指针)
   * Boost库的智能指针
   * ATL框架的智能指针(微软平台的开发框架)
   */

  demo1();

  return 0;
}
