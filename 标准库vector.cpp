#include "iostream"
#include <vector>
using namespace std;

/**
 * vector 动态数组
 */ 

class shin {};

int main(void) {
  vector<int> ve1;
  vector<double> ve2;
  vector<string> ve3;
  vector<shin> ve4;

  vector<int> ve5(10, 2); // 里面有10个2
  vector<int> ve6;
  ve6.push_back(6);
  ve6.push_back(8);

  cout << ve5.size() << endl; // 10
  cout << ve6.size() << endl; // 2

  for (vector<int>::size_type i = 0; i < ve5.size(); i++) {
    cout << ve5[i] << ' ';
  }
  cout << endl;

  vector<int> ve7(ve6);
  vector<int> ve8(10); // 10个0
  vector<string> ve9(10); // 10个空字符串

  ve9[0] = "ding1";
  cout << ve9[0] << endl;





  return 0; 
}