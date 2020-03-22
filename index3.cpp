#include <iostream>
#include "./mylib/ding.h"

// g++ index3.cpp -lcurses ./mylib/** -o index3 && ./index3

using namespace std;
int main()
{
  int res1 = func(1);
  cout << res1 << endl;
  int res2 = func(2.0);
  cout << res2 << endl;
  int res3 = func(1, 2.0);
  cout << res3 << endl;
  return 0;
}
