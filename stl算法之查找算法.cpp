#include "iostream"
#include "string"
#include "vector"
#include "list"
#include "algorithm"
#include "deque"
using namespace std;

/**
 * find()
 * find_if()
 * search_n()
 * search()
 * find_end()
 * find_first_of()
 * adjacent_find()
 */

int main(void) {

  /**
   * 以下算法对所有容器都可以用
   */



  /**
   * find和find_if
   * 但是效率慢 是线性查找
   * 对于已序的容器元素可以使用一些特定的算法
   * 比如binary_search()、includes()、lower_bound()、upper_bound()等
   */
  list<int> li;
  for (int i = 0; i < 9; i++) li.insert(li.end(), i);
  for (int i = 0; i < 9; i++) li.insert(li.end(), i);
  for_each(li.begin(), li.end(), [](int a) { cout << a; });
  cout << endl;
  list<int>::iterator pos1;
  pos1 = find(li.begin(), li.end(), 6);
  list<int>::iterator pos2;
  if (pos1 != li.end()) {
    pos2 = find(pos1++, li.end(), 6);
  };


  /**
   * search_n 用来查找连续的
   */
  deque<int> ideq;
  for (int i = 0; i < 9; i++) ideq.insert(ideq.end(), i);
  for_each(ideq.begin(), ideq.end(), [](int a) { cout << a; });
  cout << endl;
  deque<int>::iterator ideq_iter;
  ideq_iter = search_n(ideq.begin(), ideq.end(), 6, 3); // 找6个3
  if (ideq_iter == ideq.end()) {
    cout << "没有连续的6个3" << endl;
  } else {
    cout << "如果找到的话返回的迭代器是第一个3的位置" << endl;
    cout << distance(ideq.begin(), ideq_iter) << endl; // 这样可以查看下标是多少
  };

  ideq_iter = search_n(ideq.begin(), ideq.end(), 3, 6, greater<int>());
  if (ideq_iter == ideq.end()) {
    cout << "没有找到连续3个大于6的数" << endl;
  } else {
    cout << "找到啦" << endl;
  };
  // 其实下面 ↓ 这个才是正儿八经的c++的算法的写法 但是这个比较特殊 c++标准在审查的时候大佬们没检查出来 所以将错就错了
  // 一般这种带 _if 的 最后都能传个函数对象 也可以叫谓词
  // ideq_iter = search_n_if(ideq.begin(), ideq.end(), 3, bind2nd(greater<int>(), 6));
  if (ideq_iter == ideq.end()) {
    cout << "没有找到连续3个大于6的数" << endl;
  } else {
    cout << "找到啦" << endl;
  };


  /**
   * search()
   * find_end()
   * 这俩是一对儿算法
   * 只不过是因为大佬审查时候不认真所以名字起错了
   */
  // 从ideq里面找和li相等元素 返回一个迭代器
  ideq_iter = search(ideq.begin(), ideq.end(), li.begin(), li.end());
  if (ideq_iter == ideq.end()) cout << "没找到" << endl;
  // find_end 是和search一样 只不过是从后面开始找
  // int arr[] = {1, 2, 3};
  // 下面这个意思是把arr和ideq作为参数传给第五个参数谓词中
  // ideq_iter = search(ideq.begin(), ideq.end(), arr, arr + 3, [](int a, int b) { return a == b; });
  
  
  /**
   * find_first_of() 用于查找任何一个 比如查找出现3或出现6或出现9的位置
   */
  int arr[] = {1,2,3};
  // 找出现1或2或3的位置 返回一个迭代器 第三四个参数也可以传迭代器
  find_first_of(ideq.begin(), ideq.end(), arr, arr + 3);
  // find_first_of(ideq.begin(), ideq.end(), arr, arr + 3, []() {});



  /**
   * adjacent_find() 查找连续两个相等或符合谓词规则的
   */
  vector<int> ivec2;
  ivec2.push_back(1);
  ivec2.push_back(3);
  ivec2.push_back(5);
  ivec2.push_back(5);
  ivec2.push_back(8);
  ivec2.push_back(6);
  vector<int>::iterator ivec2_iter;
  ivec2_iter = adjacent_find(ivec2.begin(), ivec2.end());
  if (ivec2_iter != ivec2.end()) {
    cout << "找到了连续相等的东西" << distance(ivec2.begin(), ivec2_iter);
  };
  // 下面的谓词意思是找到后面是前面2倍的位置
  ivec2_iter = adjacent_find(ivec2.begin(), ivec2.end(), [](int a, int b) { return b / a == 2; });



  /**
   * binary_search()
   * includes()
   * 这俩都是对已序区间进行查找的算法
   */
  vector<int> ivec3;
  ivec3.push_back(1);
  ivec3.push_back(3);
  ivec3.push_back(5);
  ivec3.push_back(7);
  ivec3.push_back(9);
  ivec3.push_back(66);
  ivec3.push_back(88);
  binary_search(ivec3.begin(), ivec3.end(), 5); // 用二分查找找5
  vector<int> ivec4;
  ivec4.push_back(66);
  ivec4.push_back(88);
  includes(ivec3.begin(), ivec3.end(), ivec4.begin(), ivec4.end()); // 在ivec3中找ivec4这个区间



  /**
   * lower_bound() 查找小于xx的第一个位置
   * upper_bound() 查找大于xx的第一个位置
   * equal_range() 既包含lower也包含equal
   * 也是对已序区间进行查找
   */
  list<int> li2;
  for (int i = 0; i < 9; i++) li.insert(li2.end(), i);
  for (int i = 0; i < 9; i++) li.insert(li2.end(), i);

  list<int>::iterator list_iter;
  list_iter = lower_bound(li2.begin(), li2.end(), 5); // 找第一个小于5出现的位置
  // list_iter 是第一个小于5的那个位置的后面的位置!!!注意是后面的位置

  pair<list<int>::iterator, list<int>::iterator> range; // pair 表示一对儿
  range = equal_range(li2.begin(), li2.end(), 5); // 返回一对儿迭代器 一个大于5的位置一个小于5的位置
  






  /**
   * for_each 算法
   * for_each的用法基本上和js里的差不多
   * 不过多了一个它有返回值
   */
  class Test {
    public:
      void operator() (int num) {
        cout << num << endl;
      };
      // 可以这样返回
      double value() {
        // 这是是它的返回值
        return 666.888;
      };
      // 也可以对返回结果进行double重载
      operator double() {
        return 666.888;
      };
  };
  Test res = for_each(li.begin(), li.end(), Test());
  double res2 = for_each(li.begin(), li.end(), Test());
  cout << res.value() << endl; // 666.888
  cout << res2 << endl; // 666.888

  return 0;
}
