#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
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
