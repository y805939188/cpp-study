#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

/**
 * 
 */

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    string tempStr = "";
    int length = 0;
    int a = 0, b = 0;
    char _s;
    int _index;
    while(true) {
      if (b >= s.size()) break;
      _index = tempStr.find(s[b]);
      if (_index == -1) {
        tempStr += s[b];
        b++;
        length = max(length, (int)tempStr.size());
        continue;
      }
      _s = tempStr[_index];
      tempStr = tempStr.substr(_index + 1);
    }
    return length;
  }
};

int main(void) {

  Solution * test = new Solution();
  string s = "bbbbb";
  int len = test -> lengthOfLongestSubstring(s);

  cout << len << endl;


  return 0;
}
