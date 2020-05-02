#include "iostream"
#include "string"
#include "vector"
#include "fstream"
using namespace std;

/**
 * 
 */

int main(void) {
  fstream outfile("./txt_test.txt");
  outfile << "hello world";
  outfile.close();

  fstream infile("./txt_test.txt");
  string s;
  infile >> s;
  infile.close();
  cout << s << endl;
  return 0;
}
