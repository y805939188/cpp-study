#include "iostream"
#include "string"
#include "vector"
#include "list"
#include "deque"
using namespace std;

/**
 * 
 */

int main(void) {
  vector<int> a;
  list<int> b;
  deque<int> c;

  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  b.push_back(100);
  b.push_back(200);
  b.push_back(300);

  c.push_back(1000);
  c.push_back(2000);
  c.push_back(3000);

  for (vector<int>::size_type i = 0; i < a.size(); i++) {
    /**
     * vector和deque可以使用下标操作
     * list不行
     */
    cout << a[i] << endl;
  }

  vector<int>::size_type                   a1; // 容器尺寸
  vector<int>::iterator                    a2; // 迭代器
  vector<int>::const_iterator              a3; // 常量迭代器
  vector<int>::reverse_iterator            a4; // 逆序迭代器
  vector<int>::const_reverse_iterator      a5; // 常量逆序迭代器
  vector<int>::difference_type             a6; // 保存容器两个数据之间的距离
  vector<int>::value_type                  a7; // 值类型
  // vector<int>::reference                   a8; // 引用 引用必须初始化
  vector<int>::const_iterator              a9; // 常量引用

  list<int>::size_type                   b1; // 容器尺寸
  list<int>::iterator                    b2; // 迭代器
  list<int>::const_iterator              b3; // 常量迭代器
  list<int>::reverse_iterator            b4; // 逆序迭代器
  list<int>::const_reverse_iterator      b5; // 常量逆序迭代器
  list<int>::difference_type             b6; // 保存容器两个数据之间的距离
  list<int>::value_type                  b7; // 值类型
  // list<int>::reference                   b8; // 引用 引用必须初始化
  list<int>::const_iterator              b9; // 常量引用

  deque<int>::size_type                   c1; // 容器尺寸
  deque<int>::iterator                    c2; // 迭代器
  deque<int>::const_iterator              c3; // 常量迭代器
  deque<int>::reverse_iterator            c4; // 逆序迭代器
  deque<int>::const_reverse_iterator      c5; // 常量逆序迭代器
  deque<int>::difference_type             c6; // 保存容器两个数据之间的距离
  deque<int>::value_type                  c7; // 值类型
  // deque<int>::reference                   c8; // 引用 引用必须初始化
  deque<int>::const_iterator              c9; // 常量引用

  b2 = b.begin(); // 指向第一个
  c2 = c.end(); // 指向最后一个的下一个
  a3 = a.begin(); // 常量迭代器 不能修改




  /**
   * 在顺序容器中添加元素
   * 容器元素都是副本 对容器内的元素操作不影响原来的 比如一个list是根据一个字符串的数组创建的 不会影响到原来的数组
   * 添加元素可能会使迭代器失效
   * 避免存储end操作返回的迭代器 比如 end = xxx.end() 但是在之后进行了push操作 那这个end可能就不是end了
   */





  /**
   * 容器的关系运算符
   * 所有的容器类型都可以使用
   * 被比较的容器必须具有相同的容器类型
   * 基于容器内容元素比较
   * 容器内的元素必须自己本省有相应的关系运算符
   * 
   */

  vector<int> vec1;
  vector<int> vec2;
  vec1.push_back(2);
  vec1.push_back(2);

  vec2.push_back(1);
  vec2.push_back(2);
  // vec2.push_back(3);

  // 比较规则是 如果两个容器的长度一样 那就从头分别比较 看先找到谁的大
  // 长度如果不相等的话 长度一样的部分全都一样 那就看谁长
  // 长度相等并且元素也都相等的话 那就真的相等
  if (vec1 > vec2) cout << "vec1大" << endl;
  else if (vec1 == vec2) cout << "一样大" << endl;
  else cout << "vec2大" << endl;





  /**
   * 容器大小的操作
   */
  list<int> li1;
  li1.push_back(1);
  cout << li1.max_size() << endl; // 看这个容器最大能放多少个数据 可能是一个超大的数
  li1.resize(10, -1);
  cout << li1.size() << endl; // 10 调整容器的大小 不足的地方会根据第二个参数被自动填充上
  li1.resize(0);
  cout << li1.empty() << endl; // 1




  /**
   * 容器的访问操作
   * back()
   * front()
   * xx[n]
   * xx.at(n)
   * 
   * 注意: xx[number] 和 xx.at(number) 只适合vector和deque容器
   * 如果at或者下标越界了 就会报错
   */

  /**
   * 容器的删除操作
   * c.erase(p) 传迭代器
   * c.erase(begin, end) end是删除到end之前 end自己不会被删
   * c.clear()
   * c.pop_back()
   * c.pop_front() 只适用于list和deque
   */

  /**
   * 顺序容器的赋值与交换操作
   * c1 = c2 要求类型必须一样
   * c1.swap(c2) 类型必须一样
   * c.assign(begin, end) 要求类型相互兼容 比如 string 和 char*
   * c.assign(n, t)
   * 
   */

  vector<int> ding1;
  vector<int> ding2;
  vector<int> ding3;
  ding1.push_back(1);
  ding2.push_back(1);
  ding2.push_back(2);
  ding3.push_back(1);
  ding3.push_back(2);
  ding3.push_back(3);
  ding1.swap(ding2);
  cout << ding1.size() << endl; // 2
  cout << ding2.size() << endl; // 1
  ding1.assign(ding3.begin(), ding3.end());
  cout << ding1.size() << endl; // 3

  /**
   * size表示大小
   * capacity表示容量
   * capacity容量会随着元素的增多儿慢慢增多
   */

  cout << ding1.capacity() << endl;





  /**
   * 顺序容器的选用
   * list扩容很快因为是链表
   * vector每次扩容都是先把之前的拷贝一份儿再扩
   * deque是分区存放的 可以保存的数据比vector大很多
   * 也可以快速的二分查找等 速度上deque比vector稍微慢一点点
   * 用的时候可以优先使用vector
   * 编程的时候尽量多用迭代器 这样以后想从某个容器切换到别的容器的时候是比较容易的
   */

  return 0;
}
