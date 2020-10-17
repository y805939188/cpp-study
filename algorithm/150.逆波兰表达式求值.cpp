#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "typeinfo"
using namespace std;

/**
 * 输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * 输出: 22
 * 解释: 
 * 该算式转化为常见的中缀算术表达式为：
 *  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 *  = ((10 * (6 / (12 * -11))) + 17) + 5
 *  = ((10 * (6 / -132)) + 17) + 5
 *  = ((10 * 0) + 17) + 5
 *  = (0 + 17) + 5
 *  = 17 + 5
 *  = 22
 * 
 * 
 * 思路1:
 *  设置索引 a 从头开始扫 如果是数字就直接 a++
 *  如果是 加减乘除 的话 从 a 往前扫 扫出俩数字
 *  然后把这俩数字放到一个数组中 再根据 a 的位置的符号
 *  去做相应的运算
 *  之后把算出来的结果放到 a 的位置
 * 
 * 思路2:
 *  使用栈 从头开始扫 当扫到的是数字 就把数字入栈
 *  扫到符号的话 就从栈的末尾取出俩
 *  然后做相应的运算
 */

class Solution {
private:
  int str2digit(string str) {
    stringstream str2digit;
    string s = str;
    int n;
    str2digit << s; str2digit >> n;
    str2digit.clear();
    return n;
  }
public:
  int evalRPN(vector<string>& tokens) {
    vector<string>::size_type a = 0, b = a, c = 0;
    int val;
    int temp[2] = {};
    while(a < tokens.size()) {
      if (tokens[a] == "+" || tokens[a] == "-" || tokens[a] == "*" || tokens[a] == "/") {
        b = a - 1;
        while(true) {
          if (tokens[b] == "") {
            b--;
            continue;
          };
          temp[c] = str2digit(tokens[b]);
          tokens[b] = "";
          c++;
          b--;
          if (c >= 2) break;
        }
        if (c >= 2) {
          c = 0;
          b = a;
          if (tokens[a] == "+") {
            tokens[a] = to_string(temp[0] + temp[1]);
          } else if (tokens[a] == "-") {
            tokens[a] = to_string(temp[1] - temp[0]);
          } else if (tokens[a] == "*") {
            tokens[a] = to_string(temp[0] * temp[1]);
          } else if (tokens[a] == "/") {
            tokens[a] = to_string(temp[1] / temp[0]);
          }
          a++;
        }
      } else {
        a++;
      }
    }
    return str2digit(tokens[tokens.size() - 1]);
  }
};

// int str2digit(string str) {
//   stringstream str2digit;
//   string s = str;
//   int n;
//   str2digit << s; str2digit >> n;
//   str2digit.clear();
//   return n;
// }

int main(void) {
  // vector<string> str = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  vector<string> str = {"4","3","-"};
  Solution * test = new Solution();
  int res = test -> evalRPN(str);
  cout << res << endl;
  return 0;
}
