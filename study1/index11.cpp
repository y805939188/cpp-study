#include "iostream"
using namespace std;

/**
 * 关于 NULL 和 nullptr
 * 
 * 在新版编译器的标准中
 * NULL约等于0
 * nullptr约等于 (void*)0
 * void* 是一个特殊的指针 当不知道该指针为啥类型好指针的时候 可以写void* 
 * 
 */

// 当一个类有子类时，该类的析构函数必须是虚函数，原因：会有资源释放不完全的情况
class IDelegate {
  public:
    IDelegate() {}
    // virtual ~IDelegate() {
    ~IDelegate() { // 不加虚函数的话 下面会有个别的子类析构执行不了
      std::cout << "~IDelegate()!" << std::endl;
    }
};

class CStaticDelegate : public IDelegate {
public:
	CStaticDelegate() {}
	~CStaticDelegate() {
		std::cout << "~CStaticDelegate()!" << std::endl;
	}
};

template<class T>
class CMethodDelegate : public IDelegate {
  public:
    CMethodDelegate() {}
    ~CMethodDelegate()
    {
      std::cout << "~CMethodDelegate()!" << std::endl;
    }
  };



int main(void) {
  CStaticDelegate* demo1 = new CStaticDelegate();
  IDelegate* demo2 = new CMethodDelegate<int>();
  delete demo1;
  delete demo2;

  return 0;
}

