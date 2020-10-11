#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int last=m+n-1;
        // while(n){
        //     if(m==0||nums1[m-1]<=nums2[n-1]){
        //         nums1[last--]=nums2[--n];
        //     }else{
        //         nums1[last--]=nums1[--m];
        //     }
        // }

      if (!n) return;
      vector<int> temp;
      for (vector<int>::size_type i = 0; i < m; i++) {
        temp.push_back(nums1[i]);
      }
      if (!m) {
        for (vector<int>::size_type i = 0; i < n; i++) {
          nums1[i] = nums2[i];
        }
        return;
      }

      int index1 = 0, index2 = 0, index3 = 0;
      while(true) {
        if (temp[index1] < nums2[index2]) {
          nums1[index3] = temp[index1];
          index1++;
        } else {
          nums1[index3] = nums2[index2];
          index2++;
        }
        index3++;
        if (index1 >= temp.size() || index2 >= nums2.size()) {
          vector<int> temp2;
          int index_temp;
          if (index1 < temp.size()) {
            temp2 = temp;
            index_temp = index1;
          } else if (index2 < nums2.size()) {
            temp2 = nums2;
            index_temp = index2;
          }
          for (index_temp; index_temp < temp2.size(); index_temp++) {
            nums1[index3++] = temp2[index_temp];
          }
          break;
        }
      }
    }
};

int main(void) {
  vector<int> list1;
  list1.push_back(0);
  // list1.push_back(1);
  // list1.push_back(2);
  // list1.push_back(3);
  // list1.push_back(0);
  // list1.push_back(0);
  // list1.push_back(0);

  vector<int> list2;
  list2.push_back(1);
  // list2.push_back(2);
  // list2.push_back(5);
  // list2.push_back(6);

  Solution* res = new Solution();
  res -> merge(list1, 0, list2, 1);

  for (vector<int>::size_type i = 0; i < list1.size(); i++) {
    cout << list1[i] << endl;
  }
  return 0;
}
