#include "iostream"
#include "cmath"
#include "cassert"
#include "ctime"
#include <vector>

using namespace std;

/**
 * template 后面的class和typename用作模板的时候效果是一样的
 * 都表示后面的 T 是一个类型 比如int或者char等
 * 
 * 但是typename还可以用作告诉编译器 后面跟着的是一个类型
 */
template<class T>
void Fn(T a) 
{
  // 这里吐过不加 typename 的话 编译器就不知道后边的 T::MyType 表示的是一个类型还是变量
  typedef typename T::MyType MyType; 
  MyType length = a.GetLength; 
}

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
