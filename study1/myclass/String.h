#include "iostream"
using namespace std;


class String {
  public:
    String(const char* str); // 普通构造函数
    String(const String& other); // 拷贝构造函数
    String(String&& other); // 移动构造函数 就是 std::move
    ~String(void); // 析构函数
    String& operator= (const String& other); // 赋值函数
    // String& operator= (String&& rhs)noexcept; // 移动赋值运算符

    friend ostream& operator<< (ostream& os, const String& c); // cout输出

  private:
    char* m_data; // 用于保存字符串
};
