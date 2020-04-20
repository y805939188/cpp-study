#include "iostream"
#include "cassert"
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
  int zero = -1;
  int two = nums.size();
  for (int i = 0; i < two; ) {
    if (nums[i] == 1) i++;
    else if (nums[i] == 2) {
      two--;
      swap(nums[i], nums[two]);
    } else {
      zero++;
      swap(nums[i], nums[zero]);
      i++;
    }
  }
}

int main(void) {
  int arr1[] = { 0, 1, 1, 0, 2, 2, 1, 0, 2, 1, 1, 2, 2, 0, 0, 1, 2 };
  vector<int> arr2(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  sortColors(arr2);
  for_each(arr2.begin(), arr2.end(), [](int num) { cout << num << endl; });
}
