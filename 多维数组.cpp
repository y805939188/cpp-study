#include "iostream"
#include "string"
using namespace std;

/**
 * 
 */

int main(void) {

  // int arr[6][8]; // 6行8列
  const size_t row = 6;
  const size_t col = 8;
  int arr[row][col] = {
    {1,2,3,4,5,6,7,8},
    {1,2,3,4,5,6,7,8},
    {1,2,3,4,5,6,7,8},
    {1,2,3,4,5,6,7,8},
    {1,2,3,4,5,6,7,8},
    {1,2,3,4,5,6,7,8},
  };

  int (*p)[8]; // p是一个指针 指向一个8位数组
  p = arr;
  p = &arr[2];
  int *p_p[8]; // 这个表示p_p是一个数组 数组中的每一项都是个int类型的指针

  typedef int int_arr[6];
  int_arr *p_1; // 可以用这种方式防止忘了加(*p)
  int (*p_2)[6]; // 和上面的写法性质一样

  return 0;
}
