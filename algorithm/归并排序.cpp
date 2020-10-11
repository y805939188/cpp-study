#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

/**
 * 归并是把 N 个元素从中间切 得到两部分
 * 然后两部分再分别中间切 得到四部分
 * 之后以此类推
 * 最终能得到 N 份儿 每份儿有 1 个元素
 * 
 * 然后再返回去往上走 每走一层就做一次归并
 * 也就是说分别比较两组元素每一个元素的大小
 * 
 * 比如: 
 *          3 8 7 6 9 5 3 1           level1
 *         3 8 7 6 | 9 5 3 1          level2
 *       3 8 | 7 6 | 9 5 | 3 1        level3
 *   3 | 8 | 7 | 6 | 9 | 5 | 3 | 1    level4
 * 
 * 
 * 首先比较 3和8 得到 3 8, 然后比较 7和6 得到 6 7, 之后 9和5 得到 5 9, 最后3和1 得到 1 3
 * 
 *       3 8 | 6 7 | 5 9 | 1 3 
 * 
 * 之后用 3 8 这一组中的每一个和 6 7 组中的每一个比较 再用 5 9 和 1 3 比较
 * 也就是 3 和 6 比较 3 在前 之后 8 和 6 比 6 在前 再然后 8 和 7 比 7 在前 得到 3 6 7 8
 * 同样的 5 和 1 比较 1 在前 之后 5 和 3 比 3 在前 再然后 5 和 9 十一组 直接放到 1 3 后面得到 1 3 5 9
 *       
 *       3 6 7 8 | 1 3 5 9
 * 
 * 之后以此类推 最后得到
 *       1 3 3 5 6 7 8 9
 * 
 * 一共 8 个数, 拆分成 8 组每组 1 个元素的时候经过 3 次拆分
 * 也就是 8 / 2 / 2 / 2 = 1
 * 所以是 ㏒₂8
 * 也就是说 第一步拆分的次数 logN
 * 
 * 然后第二步
 * 分别对两组元素之间的数进行归并 这个过程是 O(N) 的复杂度
 * 
 * 所以最终归并排序的时间复杂度是 NlogN
 * 
 * 
 * 总的来说 归并排序有三步
 * 1. 集合左半拉排序
 * 2. 集合有半拉排序
 * 3. 合并左右俩集合
 */


template <class T>
void _merge(T arr[], int l, int mid, int r) {
  // 这里要操作外边传进来的arr[]
  T temp[r - l + 1]; // 所以先整出一个临时的数组 这个数组开始和arr一毛一样
  int len = r - l + 1;
  for (int i = 0; i < len; i++) {
    temp[i] = arr[i];
  }

  int kl = 0; // 记录下一个的位置
  int kr = len / 2;
  for (int j = 0; j < len; j++) {
    if (kl >= len / 2) {
      arr[j] = temp[kr];
      kr++;
    } else if (kr >= len) {
      arr[j] = temp[kl];
      kl++;
    } else if (temp[kl] <= temp[kr]) {
      arr[j] = temp[kl];
      kl++;
    } else {
      arr[j] = temp[kr];
      kr++;
    }
  }
}


template <class T>
void _mergeSort(T arr[], int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2; // 这里其实有个 l + r 大整形溢出的问题
  _mergeSort<T>(arr, l, mid); // 左半拉排序
  _mergeSort<T>(arr, mid + 1, r); // 右半拉排序
  _merge<T>(arr, l, mid, r); // 合并
};

template <class T>
void mergeSort(T arr[], int n) {
  
  _mergeSort(arr, 0, n - 1);

};


int main(void) {
  int arr[] = { 5, 7, 3, 6, 1, 9, 8, 0 };
  mergeSort<int>(arr, 8);
  for_each(arr, arr + 8, [](int a) { cout << a << " "; });
  // int arr[] = {1, 3, 2, 6};

  // _merge<int>(arr, 0, 2, 3);
  // for_each(arr, arr + 4, [](int a) { cout << a << " "; });
  return 0;
}
