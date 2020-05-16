#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 两种模板
 *  1. 类模板
 *  2. 函数模板
 * 泛型编程
 *  主要用于容器、迭代器、算法 (STL标准模板库)
 */

class Queue {
  struct Node {
    int a;
    Node* next;
  };
  public:
    Node* head;
    Node* last;
    void push(int n) {
      if (!head) {
        head = new Node();
        head -> a = n;
        last = head;
      } else {
        last -> next = new Node();
        last = last -> next;
        last -> a = n;
      };
    }
    void print() {
      Node * temp = head;
      while (temp) {
        cout << temp -> a << endl;
        temp = temp -> next;
      }
    }
};

template <class T>
class Queue_niubi {
  struct Node {
    T a;
    Node* next;
  };
  public:
    Node* head;
    Node* last;
    void push(T n);
    void print() {
      Node * temp = head;
      while (temp) {
        cout << temp -> a << endl;
        temp = temp -> next;
      }
    }
};

template<class T>
void Queue_niubi<T>::push(T n) {
  if (!head) {
    head = new Node();
    head -> a = n;
    last = head;
  } else {
    last -> next = new Node();
    last = last -> next;
    last -> a = n;
  };
}







/**
 * 函数模板
 * template <typename T>
 * template <class T>
 */

/**
 * c++ 会根据函数模板 生成多个真实的函数
 * 比如有个string类型的T就生成个string的
 * 有个int的就生成个int类型的
 */
template <typename T>
T compare(const T &v1, const T &v2) {
  if (v1 > v2) return v1;
  else return v2;
}

template <class T1, class T2>
T1& print(T1& s, const T2 val) {
  s << val << endl;
  return s;
};


int main(void) {
  Queue q1;
  q1.push(1);
  q1.push(2);
  q1.print();

  Queue_niubi<char> q2;
  q2.push('a');
  q2.push('b');
  q2.print();

  vector<string> v1;
  v1.push_back("ding1");
  v1.push_back("ding2");

  string s1("ding1");
  string s2("ding2");
  cout << compare(s1, s2) << endl; // ding2

  print(cout, "ding3"); // ding3
  print(cout, 666); // 666
  return 0;
}
