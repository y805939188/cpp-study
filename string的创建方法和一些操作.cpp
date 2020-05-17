#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
 */

int main(void) {
  string s1;
  s1 = "ding";
  string s2(5, 'd');
  string s3(s2);
  string s4(s3.begin(), s3.begin() + s3.size());

  char* str1 = "ding"; // 最后又\0
  char str2[] = "ding"; // 最后有\0
  char str3[] = { 'd', 'i', 'n', 'g' }; // 严格来说这是字符数组 后面没有 \0

  string s5(str1);
  string s6(str2, 3);
  string s7(str2 + 1, 2); // 从str3的下一位开始 往后找俩
  // string s8(str3); // 会出错的 因为它找不到 \0
  string s9(str3, 3); // 这样可以

  string s10(s1, 0, 2); // s1从0开始拿俩


  /**
   * 修改string的方法
   */
  string ss1("dingyeyeyeyeye");
  string ss2("niubi");
  string::iterator iter = ss1.begin();
  ss1.insert(iter, 'D'); // 在最前面插入D
  ss1.insert(iter, 3, 'D'); // 在前面插入3个D
  ss1.insert(0, 3, 'D'); // 从下标0开始插入 D 插3个
  ss1.insert(6, ss2); // 在下标为6的地方插入ss2这个字符串
  ss1.insert(0, ss2, 6, 8); // 在0下标的位置 插入ss2 从ss2的下标6插到下标8

  string::iterator iter2 = ss2.begin();
  string::iterator iter3 = ss2.end();
  ss1.insert(iter, iter2, iter3); // 把ss2的string全都插入到ss1之前

  ss1.assign(iter2, iter3); // ss1的所有字符将被iter2到iter3之间的字符替换
  ss1.assign(8, '6'); // 用8个6替换ss1
  ss1.erase(iter); // 删除迭代器指向的字符
  ss1.erase(ss1.begin(), ss1.end()); // 从begin删除到end









  /**
   * 只适合string类型的操作
   * 三个substr重载函数
   * 六个append重载函数
   * 十个replace重载函数
   */
  string ding1("123456789");
  string ding2 = ding1.substr(6, 8); // 从ding1第6位开始往后拿5个
  ding2 = ding1.substr(6); // 从ding1的第6位开始拿全部
  ding2 = ding1.substr(); // 直接把ding1拷贝给ding2

  ding2.append("ding"); // 添加
  ding2.insert(ding2.size(), "ding"); // 和上面的append几乎等价

  ding2.replace(6, 3, "dingye"); // 从下标6开始替换3个 第三个参数可以超过第二个参数的长度 会全量替换

  ding2.erase(6, 8); // 从6开始删除8个




  /**
   * string的查找操作
   * s.find(args)
   * s.rfind(args)
   * s.find_first_of(args)
   * s.find_last_of(args)
   * s.find_first_not_of(args)
   * s.find_last_not_of(args)
   */
  string name("ding niubiniubi");
  string::size_type position1 = name.find("ding"); // 找到的话返回下标
  if (position1 == string::npos) cout << "没有找到" << endl;

  name = "ding1 ding2 ding3";
  string numberics("0123456789");
  string::size_type position2 = name.find_first_of(numberics); // 从name中找numberics中的任意一个 也就是说能找到 1 2 3
  if (position2 == string::npos) cout << "没有找到" << endl;
  // find_first_of第二个参数可以传个下标 表示从某个下标之后开始找 可以用这种方式在循环中找到所有的

  // find_first_not_of 和它相反 是找不匹配的 比如numberics是匹配数字呢 那就把非数字的都找到






  /**
   * string对象的比较
   * s.compare(args)
   */
  string sss1("abc");
  string sss2("bcd");
  // 可以通过普通的符号比较
  // 也可以通过compare函数比较
  if (sss1.compare(s2) > 0) cout << "sss1大" << endl;
  if (sss1.compare(s2) < 0) cout << "sss2大" << endl;
  if (sss1.compare(s2) == 0) cout << "俩相等" << endl;

  if (sss1.compare(1, 2, sss2) > 0) cout << "从sss1的1位开始看后面2个和sss2比较" << endl;
  if (sss1.compare(1, 2, sss2, 1, 2) == 0) cout << "从sss1的1位开始看后面2个和sss2的1开始后面的2个比较" << endl;

  return 0;
}
