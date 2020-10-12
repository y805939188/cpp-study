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
    string reverseVowels(string s) {
        map<char, bool> m;
        m['a'] = true;
        m['e'] = true;
        m['i'] = true;
        m['o'] = true;
        m['u'] = true;
        m['A'] = true;
        m['E'] = true;
        m['I'] = true;
        m['O'] = true;
        m['U'] = true;

        int left = 0, right = s.size() - 1;

        while(true) {
            while(left < s.size() && !m[s[left]]) left++;
            while(right >= 0 && !m[s[right]]) right--;
            if (left >= right) break;
            swap(s[left], s[right]);
            left++;
            right--;
        }

        cout << s << endl;

        return "";

    }
};

// 可以不使用map 直接用 string 的find 速度会快
// class Solution {
// public:
//     string reverseVowels(string s) {
//         int i=0,j=s.size()-1;
//         string tool="aoeiuAOEIU";
//         while(i<j)
//         {
//             while(tool.find(s[i])==-1&&i<j)
//                 ++i;
//             while(tool.find(s[j])==-1&&i<j)
//                 --j;
//             if(i<j)
//                 swap(s[i++],s[j--]);
//         }
//         return s;
//     }
// };

int main(void) {
  Solution* test = new Solution();

  string s = "heelloo";
  
  test -> reverseVowels(s);

  return 0;
}
