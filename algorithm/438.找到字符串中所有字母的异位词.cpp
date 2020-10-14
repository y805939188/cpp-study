#include "iostream"
#include "string"
#include "vector"
#include "map"
using namespace std;

/**
 * 
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      // vector<int> res;
      // if (p.size() > s.size()) return res;
      // string _tempStr(p);
      // int a = 0, b = p.size() - 1;
      // int windowSize = p.size();
      
      // bool isMath = false;
      // int matchNum = 0;

      // unsigned a = 0;
      // for (unsigned b = 0; b < s.size(); b++) {
      //   matchNum = _tempStr.find(s[b]);
      //   isMath = matchNum != -1;
      //   if (_tempStr.size() > 0 && isMath) {
      //     _tempStr.erase(matchNum, 1);
      //   } else {
      //     if (!isMath) {
      //       a = a + matchNum;
      //     }
      //   }
      //   if (b - a == windowSize - 1 && !_tempStr.size()) {
      //     res.push_back(a);
      //     a++;
      //     _tempStr = p;
      //   }
      //   // for (unsigned j = 0; j < windowSize; j++) {
      //   //   matchNum = _tempStr.find(s[i + j]);
      //   //   isMath = matchNum != -1;
      //   //   if (_tempStr.size() > 0 && isMath) {
      //   //     _tempStr.erase(matchNum, 1);
      //   //   } else {
      //   //     break;
      //   //   }
      //   // }
      //   // if (!_tempStr.size()) {
      //   //   res.push_back(i);
      //   // }
      //   // _tempStr = p;
      // }
      // return res;
      // 上面这种当 p 接近 s 的长度时候会退化成 n^2


      vector<int> res;
      if (p.size() > s.size()) return res;
      int windowSize = p.size();
      map<char, int> m1;
      for (string::size_type i = 0; i < windowSize; i++) {
        m1[p[i]]++;
      }
      map<char, int> m2(m1);

      int length = s.size();
      int a = 0, b = 0;
      while(b <= length) {
        if (b - a == windowSize) {
          res.push_back(a);
          a++;
          m2[s[a - 1]]++;
        }
        if(m2[s[b]]) {
          m2[s[b]]--;
          b++;
        } else {
          if (!m1.count(s[b])) {
            a = b + 1;
            m2 = m1;
            b++;
          } else {
            a++;
            m2[s[a - 1]]++;
          }
        }
      }
      return res;
    }
};

int main(void) {
  string s = "abaacbabc";
  string p = "abc";

  Solution * test = new Solution();
  // cout << test -> findAnagrams(s, p) << endl;
  vector<int> res = test -> findAnagrams(s, p);
  for (unsigned i = 0; i < res.size(); i++) {
    cout << res[i] << endl;

  }

  return 0;
}
