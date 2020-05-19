#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

/**
 * 冒泡是比较相邻的两个 如果左边的大于右边(或小于)就把他俩交换
 * 然后再和下一个比较 如果不符合条件就再交换
 */

int main(void) {
  int arr[] = {6,8,4,1,2,3,8,6,9,7};
  size_t len = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    };
  }
  for_each(arr, arr + len, [](int a) { cout << a; });

  return 0;
}
