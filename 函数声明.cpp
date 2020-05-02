#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * 
 */

int add(int a = 1, int b = 2);

int main(void) {
  cout << add() << endl;
  return 0;
}

int add(int a, int b) { return a + b; }
