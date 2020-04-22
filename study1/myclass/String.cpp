#include "iostream"
#include "String.h"
using namespace std;

String::String(const char* str) {
  if (str == NULL) {
    m_data = new char[1];
    if (m_data != NULL) {
      *m_data = '\0';
    } else {
      exit(-1);
    }
  } else {
    int len = strlen(str);
    m_data = new char[len + 1];
    if (m_data != NULL) {
      strcpy(m_data, str);
    } else {
      exit(-1);
    }
  }
}

String::String(const String& other) {
  int len = strlen(other.m_data);
  m_data = new char[len + 1];
  if (m_data != NULL) {
    strcpy(m_data, other.m_data);
  } else {
    exit(-1);
  }
}

String& String::operator= (const String& other) {
  if (this == &other) return *this;
  //  释放原有的内容
  delete[] m_data;
  // 并重新赋值
  int len = strlen(other.m_data);
  m_data = new char[len + 1];
  if (m_data != NULL) {
    strcpy(m_data, other.m_data);
  } else {
    exit(-1);
  }
  return *this;
}

// 一般赋值时候 分为深拷贝和浅拷贝
// 可以使用引用记数 和 std::move 让渡
// move 让渡 需要写两个&&
String::String(String&& other) {
  if (other.m_data != NULL) {
    // 资源让渡
    m_data = other.m_data;
    other.m_data = NULL;
  }
}

// 移动赋值运算符
// String& String::operator= (String&& rhs)noexcept {
//   if (this != &rhs) {
//     delete[] m_data;
//     m_data = rhs.m_data;
//     rhs.m_data = NULL;
//   }
//   return *this;
// }

String::~String(void) {
  if (m_data != NULL) {
    delete[] m_data;
  }
}
