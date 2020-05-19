#include "iostream"
#include "string"
#include "vector"
#include "list"
#include "algorithm"
#include "deque"
#include "set"
#include "functional"
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





  /**
   * 区间比较算法
   * equal() 比较两个区间是否所有的元素都相等
   * mismatch() 查找两个容器中第一个不相等的数据
   * lexicographical_compare() 比较第一个区间是否比第二个区间小
   */

  vector<int> vect3;
  list<int> li3;
  for (int i = 0; i < 9; i++) vect3.insert(vect3.end(), i);
  for (int i = 0; i < 9; i++) li3.insert(li3.end(), i);

  if (equal(vect3.begin(), vect3.end(), li3.begin())) {
    cout << "两个区间相等" << endl;
  }

  if (equal(vect3.begin(), vect3.end(), li3.begin()), [](int ele1, int ele2) { return true; }) {
    cout << "第四个参数可以写谓词" << endl;
  }


  vect3[6] = 8;
  pair<vector<int>::iterator, list<int>::iterator> values;
  // 这个算法的返回值是一对儿迭代器
  // 第一个表示第一个区间第一个不相等的迭代器 第二个表示第二个区间的第一个不相等的迭代器
  values = mismatch(vect3.begin(), vect3.end(), li3.begin());
  if (values.first == vect3.end()) {
    cout << "没有找到不相等" << endl;
  } else {
    cout << *(values.first) << endl; // 8
  }
  // 第四个参数可以传谓词 less_equal表示第一个参数小于等于第二个参数
  values = mismatch(vect3.begin(), vect3.end(), li3.begin(), less_equal<int>());


  // 这个算法检查第一个区间是否小于第二个区间
  bool res1 = lexicographical_compare(vect3.begin(), vect3.end(), li3.begin(), li3.end());
  cout << res1 << endl;





  /**
   * copy()
   * copy_backward()
   * 修改性算法 把数据从一个容器中拷贝到另外一个容器中
   * 或在同一个容器中进行拷贝
   */
  vector<int> vect6(vect3.size() * 2);
  copy(li3.begin(), li3.end(), vect6.begin());
  for_each(vect6.begin(), vect6.end(), [](int a) { cout << a; });
  cout << endl;
  copy_backward(li3.begin(), li3.end(), vect6.begin());
  for_each(vect6.begin(), vect6.end(), [](int a) { cout << a; });
  cout << endl;







  /**
   * transform() 算法
   * 把一个集合区间中的元素转换并复制到另一个区间中
   * transform(b1, e1, b2, op) 把b1转换拷贝进b2
   * transform(b1, e1, b2, b3, op) 把b1和b2融合转换拷贝进b3
   * b2是目标集合 如果目标集合填了b1自己的话 那效果基本等同于for_each
   * 
   * for_each() 也是修改性算法
   * 速度快 不灵活
   * 
   * transform()
   * 速度慢 非常灵活
   */

  // negate是预定义的函数对象 表示取负
  transform(vect3.begin(), vect3.end(), vect3.begin(), negate<int>());







  /**
   * 交换算法
   * 
   */
  
  list<int>::iterator pos66 = swap_ranges(vect3.begin(), vect3.end(), li3.begin()); // 把vect3和li3中的元素进行交换
  // pos66 表示第二个区间中没有进行交换的元素




  /**
   * 填充新值算法
   * fill()
   * fill_n()
   * generate()
   * generate_n()
   */

  list<string> slist;
  slist.push_back("ding1");

  fill(slist.begin(), slist.end(), "ding2");
  for_each(slist.begin(), slist.end(), [](string a) { cout << a << endl; }); // ding2 会覆盖之前的
  // 如果之前的容器中一个数据都没有的话就必须用fill_n







  /**
   * 替换算法
   * replace()
   * replace_if()
   * replace_copy()
   * replace_copy_if()
   */

  replace(slist.begin(), slist.end(), "ding2", "ding3"); // 把slist中的ding2都换成ding3
  cout << slist.back() << endl; // ding3

  // if是可以使用函数对象的
  // replace_if(slist.begin(), slist.end(), bind2nd(less<int>, 5), 0); // 把小于5的都换成0

  // replace_copy是一遍替换一遍拷贝进第三个参数中
  // ostream_iterator 表示输出流的迭代器
  replace_copy(slist.begin(), slist.end(), ostream_iterator<string>(cout, " "), "ding3", "ding8");
  // replace_copy_if 是可以在第四个参数那里写个函数对象






  /**
   * 删除算法
   * remove()
   * remove_if()
   * 不是真正的删除 而是把后面的元素往前移动从而覆盖掉被删除的 所以长度没变
   */
  list<int> ding_test;
  for (size_t i = 0; i < 9; i++) ding_test.push_back(i);
  list<int>::iterator end = remove(ding_test.begin(), ding_test.end(), 6);
  // end ding_test被覆盖后它后面的都往前挪 end就是挪完后最后的数的那个位置
  cout << distance(end, ding_test.end()) << endl; // 能得到删除了多少
  cout << sizeof(ding_test) << endl; // 24
  for_each(ding_test.begin(), ding_test.end(), [](int a) { cout << a; });
  cout << sizeof(ding_test) << endl; // 24
  cout << endl; // 会把3覆盖掉
  ding_test.erase(end, ding_test.end()); // erase 是真正地删除

  // 把原容器中的数据删除同时复制到别的容器中
  // multiset<int> iset;
  // remove_copy_if(
  //   ding_test.begin(),
  //   ding_test.end(),
  //   inserter(iset, iset.end()),
  //   bind2nd(less<int>, 6)); // 把小于6的数据remove掉并复制到iset中

  /**
   * 删除算法
   * unique()
   * unique_copy()
   * 都可以传谓词 没写if只是因为名称不够规范
   */
  int arr1[] = {1,1,2,2,3,6,7,7,8,8,8,9};
  int size = sizeof(arr1) / sizeof(arr1[0]);
  list<int> list66;
  copy(arr1, arr1 + size, back_inserter(list66));
  list<int>::iterator pos;
  pos = unique(list66.begin(), list66.end());
  for_each(list66.begin(), list66.end(), [](int a) { cout << a; });






  /**
   * 排列组合算法
   * next_permutation()
   * prev_permutation()
   */
  while (next_permutation(list66.begin(), list66.end())) {
    cout << "如果没有下一个排列了就会返回false 有下一个组合的话就返回true" << endl;
  };





  /**
   * 重排算法、分区算法
   * random_shuffle()
   * partition()
   * stable_partition()
   */
  // random_shuffle 传个begin和end迭代器就行
  // 如果容器里的数除以2等于0就放到左边 否则就放到右边
  // partition(list66.begin(), list66.end(), not1(bind2nd(modulus<int>(), 2)));

  // stable_partition() // 稳定的分区算法






  /**
   * 排序算法
   * sort()
   * stable_sort()
   * 可对所有的容器进行排序
   * 不过不能用于list列表 因为列表不能使用随机存取迭代器
   * 所以list有个独立的成员函数sort()
   */
  sort(ideq.begin(), ideq.end()); // 从小到大排序
  sort(ideq.begin(), ideq.end(), greater<int>()); // 从大到小排序
  // stable_sort // 比sort稍微稳一点


  /**
   * partial_sort 局部排序
   * 比如有10000个数据 只对前100排
   * 比上面sort快
   */
  partial_sort(ideq.begin(), ideq.begin() + 6, ideq.end()); // 只对前6个排序
  partial_sort(ideq.begin(), ideq.begin() + 6, ideq.end(), greater<int>()); // 只对前6个从大到小排序




  /**
   * nth_element
   * 根据第n个元素排序
   * 比如排序完把最小的6个找出来
   */
  nth_element(ideq.begin(), ideq.begin() + 6, ideq.end()); // 就把最小的6个排序出来
  nth_element(ideq.begin(), ideq.begin() - 6, ideq.end()); // 就把最大的6个排序出来





  /**
   * heap算法
   * make_heap()
   * push_heap()
   * pop_heap()
   * sort_pop()
   */

  return 0;
}
