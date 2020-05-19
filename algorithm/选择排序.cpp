#include "iostream"
#include "cassert"
// #include <vector>

using namespace std;

/**
 * 选择排序是从0位开始往后找
 * 先假装最开始的0位是最小的
 * 在之后的遍历中如果发现谁比他还小就把这个数的index记录下来
 * 最后遍历完一次之后把当前为何记录下来的那位交换
 */

template<typename T>
void selectionSort(T& arr) { // 这里传递一个数组进来之后 arr会退化成一个指针 也就是 32位下sizeof 4 64位下8
  // 可以使用模板特化的方式把数组的引用传进来
  int len = (sizeof(arr) / sizeof(arr[0]));
  cout << "test:::" << len << endl;
  for (unsigned i = 0; i < len; i++) {
    int minIndex = i;
    for (unsigned j = i + 1; j < len; j++) {
      if (arr[minIndex] > arr[j]) minIndex = j;
    }
    swap(arr[i], arr[minIndex]);
  };
}


template<typename T,int N>
void FunTest(T(&_array)[N])
{
  for (int indx = 0; indx < N; ++indx) {
    _array[indx] = 0;
  }
} 


int main(void) {
  int a[6];
  FunTest(a);
  for_each(a, a + 6, [](int num) { cout << num << endl; });
  int arr[] = { 2,3,4,2,6,4,3,2,1 };
  cout << arr << endl;
  selectionSort(arr);
  // for_each(arr, arr + 8, [](int num) { cout << num << endl; });
  for (unsigned int i = 0; i < 8; i++) {
    cout << arr[i] << endl;
  }
}
