class DingTest {
  public:
    int _a;
    DingTest();
    void printDingTest();
    // 对等号运算符做重载
    // 等号的标准运算符重载要返回一个引用
    // DingTest& operator= (const DingTest& x);
    DingTest operator= (int a);
    DingTest& operator= (const DingTest& x);
};
