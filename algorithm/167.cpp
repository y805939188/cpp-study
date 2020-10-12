#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> res;
        while(true) {
            if (left <= right) break;
            int a = numbers[left], b = numbers[right];
            if (a + b == target) {
                res.push_back(left);
                res.push_back(right);
                return res;
            } else if (a + b < target) {
                left++;
            } else if (a + b > target) {
                right--;
            }
        }
    }
};
int main(void) {

  return 0;
}
