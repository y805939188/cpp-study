#include "iostream"
#include "string"
#include "vector"

/**
 * using namespace xxx
 * 表示把xxx中的东西都导入
 */
using namespace std;


namespace MyNS {
  void ding_fn() {
    cout << "这是我自己的命名空间" << endl;
  };

  namespace niubi {
    class ding {

    };
  };
};

using MyNS::ding_fn;

namespace ding = MyNS::niubi; // 这样也可以 可以给某个命名空间定义别名

int main(void) {
  using namespace MyNS;
  // MyNS::ding_fn();
  ding_fn();

  MyNS::niubi::ding d;
  return 0;
}
