#include "iostream"
#include "string"
#include "vector"
#include "fstream"
using namespace std;

/**
 * 
 */

int main(void) {
  cout << "cin的状态, 一般系统级别的错误才会导致这里错误:::" << (cin.bad()) << endl;
  cout << "cin处理流失败:::" << (cin.fail()) << endl;
  cout << "cin是否结束 一般结束就是终端中输入了control+z Windows下 mac下不知道:::" << (cin.eof()) << endl;
  cout << "cin只要不是上面三种状态 那他就是good:::" << (cin.good()) << endl;


  int val;
  while (cin >> val, !cin.eof()) { // ,逗号运算符 表示!cin.eof()是while的条件 跟最后一个逗号之前的无关
    if (cin.bad()) {
      throw std::runtime_error("io流出错");
    }
    if (cin.fail()) {
      cerr << "无效类型" << endl;
      cin.clear(); // 把那些什么fail bad之类的标志都清空 恢复到正常流的状态
      cin.ignore(200, '\n'); // 要么清楚流中的前200个 要么清除到\n换行之前
      continue;
    }
  }

  cin.setstate(fstream::badbit); // 可以用fstream自带的二进制位自定义流的状态

  fstream::iostate old_state = cin.rdstate(); // 也可以拿到流的状态

  cin.clear(); // 最后一定要清除流的状态 因为流是共享的 这里如果把状态改废了 别的地方再用也费劲了

  return 0;
}
