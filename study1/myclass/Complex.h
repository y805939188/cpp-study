class Complex {
  public:
    Complex(); // 构造函数可以有重载 这个没有参数的叫做默认构造函数
    // 一旦创建带参数的自定义构造函数的话 默认构造函数就必须自己手动声明
    Complex(double a, double b); // 表示Complex中要有构造函数
    // 析构函数是当类的实体销毁的时候自动调用
    // 析构函数这里一定要写个 virtual
    virtual ~Complex(); // 表示你Complex中要有析构函数
    
    Complex(const Complex& x); // 拷贝构造

    void PrintVal();

    // 逻辑可以写在头文件中
    
    // const 修饰这整个函数 表示函数体内部的成员变量都不能修改
    // double getA() const {
    //   return _a;
    // }

    // double getB() const {
    //   return _b;
    // }

    // void setDoubleA(double c) {
    //   _a = c;
    // }

    // void setDoubleB(double d) {
    //   _b = d;
    // }
    double getA() const;
    double getB() const;
    void setDoubleA(double c);
    void setDoubleB(double d);

    // 运算符重载
    // ↓返回类型         ↓不可变的 ↓引用类型 x 直接使用x 如果不加& 就开辟一块和x一样的空间
    Complex operator+ (const Complex& x);
    //        ↑表示+操作符      ↑ 这里加&表示引用类型 不会再开辟一块儿新空间

    // 对等号运算符做重载
    // 等号的标准运算符重载要返回一个引用
    Complex& operator= (const Complex& x);

    Complex& operator++ (); // 前置++
    Complex operator++ (int); // 后置++

    // Complex

  private:
    double _a;
    double _b;
  private: int _ding;


};
