#include "iostream"
#include "fstream"
using namespace std;

/**
 * 拷贝二进制文件
 */
bool copyFile(const string& src, const string& dst) {
  // 源文件以二进制的方式存储
  ifstream in(src.c_str() /** c_str可以获取到字符串 */, ios::in | ios::binary /** 使用二进制流的方式打开 */);
  ofstream out(dst.c_str(), ios::out | ios::binary | ios::trunc  /** 使用覆盖的方式写入 */);
  if (!in || !out) return false;
  char temp[2048];
  while (!in.eof()) {
    // 往temp里头读 每次读取2048个
    in.read(temp, 2048);
    streamsize count = in.gcount(); // 实际读取到的长度
    out.write(temp, count); // 把temp中的count位写入到out
  };
  in.close();
  out.close();
}

int main() {

  fstream fout;
  // ios::app 表示追加append
  fout.open("./text.txt", ios::app);
  if (fout.fail()) {
    cout << "文件不存在 打开失败" << endl;
  }

  // int a;
  // int index = 0;
  // while (cin >> a) {
  //   fout << "number is:  " << a << endl;
  //   if (index++ > 3) break; 
  // };
  // cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // 晴空缓存区脏数据
  fout << "6666";
  fout.close();

  return 0;
}
