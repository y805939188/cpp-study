#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 基类的static成员 在整个继承层次中只有一个实例
 * 访问方法
 *  基类名::成员名
 *  子类名::成员名
 *  对象.成员名
 *  指针 -> 成员名
 *  直接成员名
 */

class A {
  private:
    static int niubi;
  public:
    void addNiubi() {
      this -> niubi += 1;
    };
    int getNiubi() {
      return this -> niubi;
    };
    static void addNiubi2() {
      // static里头不能使用this
      niubi += 1;
    };
};

int A::niubi = 666;









class AA {
  public:
    static std::size_t count() {
      return 66;
    };
  protected:
    /**
     * 定义成 const 才能直接初始化 否则不能直接这里初始化
     */
    const static std::size_t count2 = 88;
};

class BB: public AA {
  public:
    void myf(const BB &b1, const BB* b2) {
      // AA::count2 = 88;

      cout << AA::count2 << endl;
      cout << BB::count2 << endl; // 因为BB继承了AA
      cout << b1.count2 << endl; // b 是BB类型的对象 所以可以通过点儿访问
      cout << b2 -> count2 << endl; // 通过指针的箭头符号也可以访问
      cout << count2 << endl; // 直接访问也行......shit......
    };
};

class CC: public BB {
  void myf(const BB &b1, const BB* b2) {
    cout << AA::count2 << endl;
    cout << BB::count2 << endl; // 因为BB继承了AA
    cout << b1.count2 << endl; // b 是BB类型的对象 所以可以通过点儿访问
    cout << b2 -> count2 << endl; // 通过指针的箭头符号也可以访问
    cout << count2 << endl; // 直接访问也行......shit......
  };
};




int main(void) {
  A* test1 = new A;
  A* test2 = new A;
  test1 -> addNiubi();
  test2 -> addNiubi();
  cout << test1 -> getNiubi() << endl; // 668
  cout << test2 -> getNiubi() << endl; // 668
  // 俩类共享同一个static属性

  A::addNiubi2();
  cout << test1 -> getNiubi() << endl; // 669

  return 0;
}
