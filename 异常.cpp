#include "iostream"
#include "exception"
using namespace std;

/**
 * 标准异常
 *  exception
 *  runtime_error
 *  rang_error
 *  overflow_error
 *  underflow_error
 *  logic_error
 *  domain_error
 *  invalid_argument
 *  length_error
 *  out_of_range
 *  bad_alloc
 */

template <class T>
class Error {
  public:
    class MyError: public std::exception {
      public:
        virtual const char *what() const throw() {
          return "这里是一个错误 what方法是重载exception重的waht方法";
        }
    };
    void throwError() {
      throw MyError();
    }
};

int main(void) {
  try {

  } catch(bad_alloc err) {
    // 比如一直new 不停new的话 可能堆空间会不够就会触发这个异常
    cout << err.what() << endl;
  } catch (...) {
    // 这里可以用三个点捕获所有的异常
    // 不过最好的做法是先分别捕获能写出来的异常
  }

  return 0;
}
