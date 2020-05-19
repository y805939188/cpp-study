#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

/**
 * 插入排序是选择一个元素 每次和前面的比如果 小就放在前面 再和更前面的比 以此类推
 */

int main(void) {
  int arr[] = {6,8,4,1,2,3,8,6,9,7};
  size_t len = sizeof(arr) / sizeof(arr[0]);
  cout << len << endl;
  for (int i = 1; i < len; i++) {
    for (int j = i; j > 0 && arr[j] < arr[j - 1] ; j--) {
      swap(arr[j], arr[j - 1]);
    };
  }
  for_each(arr, arr + 10, [](int a) { cout << a; });






  /**
   * 插入排序虽然能提前终止内部的循环
   * 但是效率比选择低 因为swap这个操作中
   * 有三次赋值操作
   * 
   * 所以可以对插入排序进行优化
   * 原理一样
   * 用一个数和前面的比 先把这个数拷贝一份儿
   * 然后和前面的比 如果比前面的小就把前面的挪到当前这个数的位置
   * 然后再和前前面的比 如果比前前面的小就把前前面的挪到这个位置
   * 再依次类推往前比较 这样能减少赋值操作
   */

  cout << endl;
  for (int i = 1; i < len; i++) {
    int num = arr[i];
    int j; // 用j记录最终num要放的位置
    for (j = i; j > 0 && arr[j - 1] > num; j--) {
      arr[j] = arr[j - 1];
    };
    arr[j] = num;
  }
  for_each(arr, arr + 10, [](int a) { cout << a; });


  /**
   * 插入排序虽然是 n^2 的排序
   * 但是当序列在近乎有序的情况下
   * 它的效率非常高 直接变成On
   */



  return 0;
}
