#include <iostream>
#include <say-hello/hello.h>
using namespace std;

/**
 * 
 */

int main(void) {
  hello::say_hello();
  cout << "由于main.cpp链接了say-hello 所以这里面也可以用这个宏" << SAY_HELLO_VERSION << endl;
  return 0;
}
