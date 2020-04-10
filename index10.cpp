
class Parent {
  // 子类继承parent后 如果想实现一个和父类行为不一致的niubi的话
  // 那这个niubi前头就得加virtual 类似多态
  // virtual void niubi() {  };
  virtual void niubi() = 0; // 或者这么写 也表示它是一个抽象类
};

class Child: public Parent {
  // 这种简写 就相当于直接把传进来的ding赋值给了内部的_ding
  Child(int ding1, double ding2): _ding1(ding1), _ding2(ding2) {};
  private:
    int _ding1;
    double _ding2;
};
