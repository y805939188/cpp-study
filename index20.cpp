#include "iostream"
using namespace std;

/**
 * cpp 多线程
 * c++ 11 之后支持
 */

#include "thread"
#include "mutex" // 互斥锁

mutex g_mutex;
void Fn1() {
  // 因为cout属于共享资源
  // 所以不加锁的话 两条线程可能会抢占资源
  // 导致cout输出不符合预期
  g_mutex.lock();
  cout << "test1" << endl;
  g_mutex.unlock();
}

void Fn2(const char* str) {
  // 所以这里在多线程的时候应该对所有的共享资源加上锁
  g_mutex.lock();
  cout << str << endl;
  g_mutex.unlock();
}

class Test {
  public:
    Test(): a(0) {};
  private:
    int a;
};

int main(void) {

  thread t1(Fn1);
  // 报错的原因是 MacOS的g++使用clang 默认不支持C++11多线程 编译指令加上-std=c++11就好 (tasks.json)
  // 不过这里应该是vscode的语法检查的问题
  // task.json中加上 -std=c++11 不好使的话就在首选项里头搜索c++ 然后改
  thread t2(Fn2, "niubi");
  // join 表示当该条线程执行完才执行主线程 也就是main函数中接下来的内容
  t1.join();
  t2.join();
  // 注意 如果是thread传参 想传引用值进去的话 thread t3(&xxx) 这样不好使 得用ref关键字 thread t4(ref(xxx))

  return 0;
}
