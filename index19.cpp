#include "iostream"

/**
 * boost库 相当于jquery => js
 * 是对stl标准库的一些补充
 * 比如下面那个hpp里头就有类型转换的方法
 * 
 * mac下安装方法 brew install boost
 * 一般是安装在 /usr/local/Cellar/boost 中
 * 然后 ⬆️ + command + p 之后输入 configur 然后选择c++的配置
 * 之后 .vscode 里面就有 c_cpp_properties.json 这个了
 * 最后把 /usr/local/Cellar/boost/xxxx(version)/include 添加进includePath
 */
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

int main(void) {
  int i = boost::lexical_cast<int>("123");
  // 或者直接在文件最上方加上 using boost::lexical_cast;
  using boost::lexical_cast;
  string s = lexical_cast<string>(1.23);

  cout << i << "::::" << s << endl;

  try {
    int num_err = lexical_cast<int>("abcd");
  } catch (boost::bad_lexical_cast& e) {
    cout << "这里出现error::" << e.what() << endl;
  }

  return 0;
}
