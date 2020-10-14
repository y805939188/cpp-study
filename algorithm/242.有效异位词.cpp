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
    bool isAnagram(string s, string t) {
        map<char, int> m1;
        for (string::size_type i = 0; i < s.size(); i++) {
            m1[s[i]]++;
        }
        for (string::size_type j = 0; j < t.size(); j++) {
            if (m1.count(t[j]) && m1[t[j]]) {
                m1[t[j]]--;
            } else {
                if (!m1.count(t[j])) {
                    return false;
                }
            }
        }
        map<char, int>::iterator iter;
        for (iter = m1.begin(); iter != m1.end(); iter++) {
            if (iter -> second) {
                return false;
            }
        }
        return true;
    }
};

int main(void) {
  string s = "rat", t = "cat";
  Solution * test = new Solution();
  bool res = test -> isAnagram(s, t);
  cout << res << endl;

  return 0;
}
