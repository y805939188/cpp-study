#include "iostream"
using namespace std;

int main(void) {
  // 普通的char只能写英文
  // 英文之外的比如中文或者日文啥的都要用宽字符
  wchar_t test1 = L'中'; // L是告诉编译器要作为宽字符
  cout << sizeof(test1) << endl; // 宽字符占4字节
  /**
   * 处理中文宽字符的时候 输出print之类的可能会存在问题
   * 可参考 https://www.bilibili.com/video/BV1P7411k7Km?p=4 第56分钟左右
   */
  cout << "这是一条"
    "特别长的"
    "字符串" << endl; // 会自动拼接上
  cout << "这里可以 \
    进行换行 \
  " << endl;
}
