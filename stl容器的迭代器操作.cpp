#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 每种容器都有自己的迭代器
 * 所有迭代器接口都一样
 * 常用迭代器操作
 *  *iter
 *  ++iter
 *  --iter
 *  iter1 == iter2
 *  iter1 != iter2
 * vector 和 deque 有一些额外的迭代器操作
 *  iter + n
 *  iter - n
 *  > 、>= 、< 、<=
 * 迭代器的范围
 *  begin/end
 *  first/last
 * 
 * 
 * 注意
 *  iter.end() 并不是指向最后一个 而是指向了最后一个地下一个 c++ 内部的一个特殊的标记
 */

int main(void) {

  return 0;
}
