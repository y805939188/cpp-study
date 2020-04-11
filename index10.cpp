#include "iostream"
using namespace std;

class Parent {
  // 子类继承parent后 如果想实现一个和父类行为不一致的niubi的话
  // 那这个niubi前头就得加virtual 类似多态
  // virtual void niubi() {  };
  // virtual void niubi() = 0; // 或者这么写 也表示它是一个抽象类
};

class Child: public Parent {
  // public:
    // 这种简写 就相当于直接把传进来的ding赋值给了内部的_ding
    // Child(int ding1, double ding2): _ding1(ding1), _ding2(ding2) {};
    // void niubi() {
    //   cout << "niubi" << endl;
    // };
    // void niubi2() {

    // }
  private:
    // int _ding1;
    double _ding2;
};

/**
 * windows下
 * 一个类的实例在内存中的表现
 * 实际就只包含它的成员属性以及一个指向父类的所有virtual函数的指针
 * 所以windows下sizeof一个实例的话 得到的是它的成员属性的大小加上一个4字节的virtual指针大小
 * 然后指向virtual虚函数数组的这个指针中 存放的也是指针 每个指针指向不同的virtual虚函数
 * 
 * 但是mac下暂时不知道
 * 
 * 对于它的成员方法的话 其实是作为普通函数存到别的地方了
 * 在这种成员方法被调用的时候 其实是先获取到this的地址 存到exc寄存器中
 * 然后在方法中使用的时候去exc寄存器中找该对象
 * 
 */

int main(void) {
  // Child test1(1, 2.0);
  Child test1;
  cout << sizeof(test1) << endl;
  return 0;
}
