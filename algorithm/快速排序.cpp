#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 快速排序
 * 每次从选定一个基点元素(pivot)
 * 之后想办法把这个pivot挪到排好序的时候它所在的位置
 * 比如 
 *  3 5 7 2 6 1 8
 *  假设选个 3
 *  2 1 3 5 7 6 8
 * 此时会有一个情况就是 3 之前的所有元素都小于 3 而 3 之后的所有元素都大于 3
 * 之后要对小于 3 以及大于 3 的两部分再分别使用快速排序进行排序
 * partition
 */

void quickSort(vector<int>& arr, int left, int right) {
  if (!arr.size()) return;
  if (left >= right) return;
  // 一定要设置随机种子以及随机选择
  // 否则的话当数组完全有序的情况下, 该nlogn的算法会退化为 n^2
  swap(arr[left], arr[rand() % (right - left + 1) + left]);
  int pivot = arr[left];
  int i = left + 1;
  int j = right;
  while(true) {
    while(i <= right && arr[i] <= pivot) i++;
    while(j >= left + 1 && arr[j] >= pivot) j--;
    if (i >= j) break;
    swap(arr[i], arr[j]);
  }
  swap(arr[left], arr[j]);
  quickSort(arr, left, j - 1);
  quickSort(arr, j + 1, right);
}

// int *generateRandomArray(int n, int rangeL, int rangeR) {
// 	assert(rangeL <= rangeR);
// 	int *arr = new int[n]; // 创建一个 n个元素的数组
// 	srand(time(NULL)); // 随机种子
// 	for (int i = 0; i < n; i++)
// 	  arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
// 	return arr;
// }

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        this -> quickSort(nums, 0, nums.size() - 1);
        
        return nums[nums.size() - k];
    }

    void quickSort(vector<int>& arr, int left, int right) {
        if (!arr.size()) return;
        if (left >= right) return;
        // swap()
        int pivot = arr[left];
        int i = left + 1;
        int j = right;
        while(true) {
            while(i <= right && arr[i] < pivot) i++;
            while(j >= left + 1 && arr[j] > pivot) j--;
            if (i >= j) break;
            swap(arr[i], arr[j]);
        }
        swap(arr[left], arr[j]);
        quickSort(arr, left, j - 1);
        quickSort(arr, j + 1, right);
    }
};

int main(void) {
  vector<int> testArr;

  int n = 20;
  int rangeL = 1;
  int rangeR = 50;
  // int *arr = new int[n]; // 创建一个 n个元素的数组
	srand(time(NULL)); // 随机种子
	for (int i = 0; i < n; i++)
    testArr.push_back(rand() % (rangeR - rangeL + 1) + rangeL);


  // testArr.push_back(3);
  // testArr.push_back(6);
  // testArr.push_back(18);
  // testArr.push_back(15);
  // testArr.push_back(5);
  // testArr.push_back(13);
  // testArr.push_back(1);
  // testArr.push_back(11);
  // testArr.push_back(5);
  // testArr.push_back(8);
  // testArr.push_back(0);

  // testArr.push_back(3);
  // testArr.push_back(3);
  // testArr.push_back(3);
  // testArr.push_back(3);
  // testArr.push_back(3);
  // testArr.push_back(3);
  // testArr.push_back(3);
  // testArr.push_back(3);
  // testArr.push_back(3);
  // testArr.push_back(3);
  // testArr.push_back(3);

  for (vector<int>::size_type i = 0; i < testArr.size(); i++) {
    cout << testArr[i] << ',';
  }
  cout << endl;

  quickSort(testArr, 0, testArr.size() - 1);

  cout << "-------------" << endl;

  for (vector<int>::size_type i = 0; i < testArr.size(); i++) {
    cout << testArr[i] << ',';
  }
  return 0;
}
