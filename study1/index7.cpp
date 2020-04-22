#include "iostream"
using namespace std;

class Test {
  public:
    Test MyFn();
};

Test Test::MyFn() {
  return *this;
};

class Test2 {
  public:
    Test2* MyFn();
};

Test2* Test2::MyFn() {
  return this;
};

class Test3 {
  public:
    Test3 MyFn();
    void PrintFn();
};

/**
 * 关于 return *this 的时候 返回类型是 Test& 可以优化返回类型是 Test 的原因
 * 返回 Test3& 就相当于
 *  1. Test3 & test = *this;
 *  2. renturn test;
 * 这样返回的只是一个引用 内存空间是一样的
 * 
 * 返回 Test3 不加 &就相当于:
 *  1. Test3 test = *this;
 *  2. return test;
 * 这样声明出来并返回的test虽然内容和*this一样, 但是它是在栈中重新生成的 地址并不一样
 * 
 */
Test3 Test3::MyFn() {
  Test3 test = *this;
  return test;
};

void Test3::PrintFn() {
  Test3 test1 = *this;
  cout << "test1的地址是:  " << &test1 << endl;
  cout << "this的地址是:  " << this << endl;
}

class Test4 {
  public:
    Test4& MyFn();
    void PrintFn();
};

Test4& Test4::MyFn() {
  return *this;
};

void Test4::PrintFn() {
  cout << this << endl;
}

class Test5 {
  public:
    Test5();
    Test5(const Test5& x); // 拷贝构造的写法
    Test5 MyFn();
    void PrintFn();
    virtual ~Test5();
};

Test5::Test5(const Test5& x) {
  cout << "这里是拷贝构造, 当成员方法返回临时对象或*this之类的时候会触发, 直接绕过普通构造" << endl;
}

Test5::Test5() {
  cout << "执行了test5的构造函数" << endl;
}

Test5 Test5::MyFn() {
  cout << "这里跌test5的地址是" << this << endl;
  return *this;
};

Test5::~Test5() {
  cout << "执行了test5的析构函数" << endl;
}

void Test5::PrintFn() {
  cout << this << endl;
}


class Test6 {
  public:
    // 重载标准输入输出
    // 返回一个标准输出流   该重载会传进来俩东西 一个标准输入流 一个当前对象
    // 在该重载中 可能会用到 x.a 但是a是一个私有变量 无法访问
    // 所以类似的这种情况下 可以给他加个friend修饰符 表示可以临时访问
    friend ostream& operator<< (ostream& os, const Test6& x);
    // 这个表示重载标准输入流
    // istream是c++系统库提供的标准输入
    friend istream& operator>> (istream& is, Test6& x);
  private:
    int a;
};

ostream& operator<< (ostream& os, const Test6& x) {
  // P.S. 使用标准输出时候需要在头文件中引入iostream
  os << "这里的私有变量输出是" << x.a;
  return os;
};

istream& operator>> (istream& is, Test6& x) {
  is >> x.a;
  return is;
};

int main(void) {
  // int ding1 = 1;
  // // int * ding2 = &ding1;
  // Test3 test1 = Test3();
  // test1.PrintFn();

  // Test2 test2 = Test2();
  // Test2* test3 = test2.MyFn();

  // Test4 test4 = Test4();
  // Test4 test5 = test4.MyFn();
  // Test4& test6 = test4.MyFn();

  // test4.PrintFn(); // 这个test6是一样的
  // cout << &test5 << endl; // 它的地址不一样
  // cout << &test6 << endl; // 这个和PrintFn()是一样的

  // Test5 test7 = Test5();
  // // Test5& test8 = test7.MyFn(); // 会报错
  // Test5 test9 = test7.MyFn(); // 只能用非引用的接收
  // Test5& test10 = test9; // 这样可以
  // // 如果方法返回类型是 引用类型 那接收的时候既可以直接 Test& xxx = yyyyy;
  // // 也可以 Test xxx = yyyyy;
  // // 只是加了&的不会消耗新的内存空间 不加&就会产生新的内存空间
  // // 如果成员方法的返回类型是不加&的普通类型 那接收的时候只能写 Test xxx = yyyyy;


  cout << "------------------" << endl;
  Test5 test11 = Test5();
  Test5 test12 = test11.MyFn();
  cout << "这里的test12的地址是" << &test12 << endl;
  // MyFn虽然return的是*this
  // 但是触发了拷贝构造 返回的只是一个新的 地址不同的副本

  Test5 test13 = Test5(test12); // 这样直接用一个同类型的来创建一个新的同类型对象 也会触发拷贝构造

  Test6 test14 = Test6();
  cout << "这里的test14对象是" << test14 << endl;

  int i;
  cin >> i; // cin是客户端输入 >> 表示流向 从输入流向 i变量

  Test6 test15 = Test6();
  cin >> test15;
  cout << test15 << endl;



  return 0;
}
