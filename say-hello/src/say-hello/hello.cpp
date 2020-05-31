#include <iostream>
#include "hello.h"


void hello::say_hello () {
  std::cout << "say hello ding" << std::endl;
  std::cout << "version is" << SAY_HELLO_VERSION << "\n";
}

