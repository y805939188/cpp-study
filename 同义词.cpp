#include "iostream"
using namespace std;

/**
 * 可以使用 typedef 定义同义词 
 */

// 相当于说把int起了个名为分数的同义词
typedef double 分数;

// 定义一个结构体 起个同义词叫MyName
typedef struct {
  分数 a;
  int b;
} MyName;

int main(void) {
  // 如果写个int类型的话 那就只是个int类型
  // 但是如果有个同义词的话 那就一下能知道 a 是个分数类型
  // 而且如果有别的很复杂的类型的话 可以定义个简单明了的类型名字
  分数 a = 66.66;

  return 0;
}
