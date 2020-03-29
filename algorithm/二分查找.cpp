#include "iostream"
#include "cmath"
#include "cassert"
#include "ctime"
#include <vector>

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target) {
  int l = 0, r = n - 1;
  while(l <= r) {
    // int mid = (l + r) / 2;
    int mid = l + (r - l) / 2; // 当l+r足够大超过了整形的时候 c++不报错 所以换成减法的形式 才没有bug
    if (arr[mid] == target) {
      return mid;
    }
    if (target > arr[mid]) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return -1;
}

int main(void) {
}
