// #include "stdafx.h" 这个是在windows系统下自动创建的一个头文件 便于做项目管理用的
#include "iostream" // 这个是系统库
#include <assert.h> // assert是断言的意思 可以不使用cout endl这种输出 可以直接用这个assert做断言
#include <vector> // 面向对象的动态数组库 系统自带 要和下面的std命名空间一块儿用
using namespace std; // 这个是系统库中包含的命名空间
// 其实printf也可以输出 只是printf是c语言中的输出方法

// command + R 或者 + T是快捷键的编译
int main(void) {
  int a = 10;
  int b = 20;
  // cout 指的是c++中的输出 标准输出
  // end 表示结束 l表示结束一行
  // 用cout和endl一定要在上头包含iostream和using namespace std 否则报错
  // 这里可以不加std:: 加了表示要使用这个命名空间下的这个东西
  std::cout << a + b << std::endl;
  std::cout << 15 / a << std::endl; // 1
  std::cout << 15.0 / a << endl; // 1.5
  std::cout << a++ << endl; // 10
  std::cout << a << endl; // 11
  std::cout << ++a << endl; // 12

  // c++中没有三等号 这里用括号表示优先级高
  std::cout << (a == b) << endl; // 0
  std::cout << (a != b) << endl; // 1=

  a = 10;
  b = 0;
  // bool a = true;
  // bool b = false; 
  std::cout << (a && b) << std::endl; // 0
  std::cout << (b || a) << std::endl; // 1 注意c++中不会说返回为true的那个
  std::cout << !(a && b) << std::endl; // 1
  std::cout << (a == true) << std::endl; // 0
  assert(!(a && b)); // 断言的内容必须是true 否则会报错

  // 位运算
  a = 10; // 010101
  b = 20; // 10100
  // c++中 0 开头并且后面的不大于7就表示一个八进制的数
  // 0x开头的表示一个十六进制的数
  // 0b开头的标识二进制
  int c = 0b01010; // 10
  int d = 0b10100; // 20
  cout << (a & b) << endl; // 01010 & 10100 = 00000 ==> 0
  cout << (a | b) << endl; // 01010 | 10100 = 11110 ==> 30
  cout << (a ^ b) << endl; // 01010 ^ 10100 = 11110 ==> 30 异或是两位不同才返回1
  cout << (~a) << endl; // ~0000000000001010 = 1111111111110101 ==> 000000000000001011（这个是补码 ~逻辑非虽然是先取反 但是在转换成十进制的时候会用补码表示） ==> -11
  cout << (a << 2) << endl; // 00001010 << 2 = 00101000 ==> 40
  cout << (a >> 2) << endl; // 00001010 >> 2 = 00000010 ==> 2

  /**
   * 杂项运算符
   * 1. sizeof 返回变量的大小
   * 2. : ? 三目运算符
   * 3. , 逗号运算符 顺序执行一系列运算, 整个表达式的值以最系列中最后一个表达式的值为准 比如 a, b, c 最后悔返回c
   * 4. . -> 点和箭头运算符 用于引用类、结构和共用体的成员
   * 5. Cast 强制类型转换 int(2.200) 会强制返回2 不建议用这种方式 因为这种方式是比较危险的 比如整形转换成浮点的时候会丢失精度
   * 6. & 指针运算符 会返回变量的地址 &a 会返回a变量的实际地址
   * 7. * 指针运算符 指向一个变量 *var 将指向变量var
   */
  a = 10;
  b = 20;
  c = 30;
  int h, i;
  float g = 6.6;
  cout << sizeof(a) << endl; // 4 返回的是int类型占多少位
  int e = (h = 10, g = 20, c = h + i); // 返回c
  cout << e << endl; // 30
  cout << int(g) << endl; // 6
  cout << &e << endl; // 返回变量e的指针 0x7ffxxxxxxxx 酱婶的
  int *f = &e; // * 表示定义一个指针 不是直接赋一个值 这个f变量会记录下一个指针 就可以通过一个变量找到另一个变量 从而间接引用 如果 int *g = a 用*定义一个值那就回报错
  cout << f << endl; // 0x7ffxxxxxxxx
  cout << *f << endl; // 30 // 给这个指针前头再加个*表示要取这个指针对应的那个位置的值

  /** 定义结构体 */
  typedef struct index
  {
    /* data */
    short Sunday = 0;
    short Monday = 1;
    short Tuesday = 2;
    short Wednesday = 3;
    short Thursday = 4;
    short Friday = 5;
    short Saturday = 6;
  } Week; // 结构体的名字
  Week w; // 用结构体定义一个变量
  cout << w.Sunday << endl; // 0
  cout << sizeof(w) << endl; // 14 因为每个short都2byte的 7天所以是14字节

  /**
   * 数组: 代表内存里一组连续的同类型的存储区
   * 可以用来把多个存储区合并成一个整体
   */
  int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, }; // 现在只有8个
  cout << sizeof(arr) << endl; // 40
  cout << arr[9] << endl; // 0
  // cout << arr[11] << endl; // 这个不会报错但是会有问题
  for (int index = 0; index < 10; index++) {
    if (index == 9) {
      cout << arr[index] << endl;
    } else {
      cout << arr[index] << " ";
    }
    
  } // 输出1 2 3 4 5 6 7 8 0 0
  int arr2[5] = {1, 2, 3, 4, 5};
  int *p = arr2; // 这个相当于让p存放了arr2的arr2[0]的指针位置
  cout << *(p + 2) << endl; // 3 这里的p是arr2[0]的指针 +2 相当于让这个指针往右移俩 所以*之后会返回3
  int arr3[10] = {};
  int len = sizeof(arr3) / sizeof(arr3[0]); // c++里算长度得他娘的这么算
  cout << len << endl;
  int arr4[2][4] = { {1,2,3,4}, {5,6,7,8} };
  arr4[0][2] = 99;
  cout << arr4[0][2] << " "; // 3
  cout << endl;

  /**
   * vector(向量) 这个是面向对象方式的动态数组
   * int a[4] = {1,2,3,4};
   * 然后 a[4] = 5; 的话会报错 说访问非法内存 因为容量不够 下标越界
   */

  // vector<int> vec = {1}; 在c++ 98 中不允许直接对vector列表进行初始化赋值 会报错的
  // 不过c++ 11中可以直接赋值

  //默认初始化,不带参数的构造函数初始化
  vector<int> vec1;
  vec1.push_back(5);
  cout << vec1[0] << endl; // 5
  //带参数的构造函数初始化
  vector<int> vec2(10); //初始化10个默认值为0的元素
  vector<int> vec3(10, 1);//初始化10个值为1的元素
  cout << vec2[8] << endl; // 0 因为每项都是0
  cout << vec3[8] << endl; // 1 每项都是1

  //通过数组地址初始化
  int test[5] = { 1, 2, 3, 4, 5 };
  vector<int> vec4(test, test + 5);
  cout << vec4[4] << endl; // 5

  //通过同类型的vector进行初始化
  vector<int> vec5(10, 1);
  vector<int> vec6(vec5);
  cout << vec6[5] << endl; // 1

  //通过迭代器进行初始化
  vector<int> vec7(10, 99);
  vector<int> vec8(vec7.begin(), vec7.end());
  vec8.push_back(88);
  cout << vec8[10] << endl; // 88
  vector<int> vec9(vec7.begin(), vec7.end() - 1);
  cout << "size1是" << vec9.size() << endl; // 9
  cout << "capacity1是" << vec9.capacity() << endl; // 9 capacity是容量的意思
  vec9.push_back(1);
  cout << "size2是" << vec9.size() << endl; // 10
  cout << "capacity2是" << vec9.capacity() << endl; // 18 push_back不是说添加一个就扩容一个 而是一次性扩容一倍
  vec9.insert(--vec9.end(), 66); // 在末尾之前插入一个66
  // vec9.insert(8, 66); 这样会报错
  cout << vec9[vec9.size() - 2] << endl; // 66
  vec9.pop_back(); // 从尾部删除
  vec9.erase(vec9.end() - 1); // 从中间某个位置擦除
  cout << vec9.size() << endl; // 9
  // P.S. .end() .begin()都是返回的迭代器 不是直接返回一个数字

  /**
   * 字符串
   * 字符串是以 空字符('\0') 结束的字符数组
   * 空字符'\0'会自动添加到字符串的内部表示
   * 在声明字符串变量时, 应该为这个空字符结束符预留一个额外的元素的空间 
   */
  char str1[11] = { "helloworld" }; // 如果字符串长度+1超过了定义的长度会报错
  cout << str1 << endl;

  /**
   * c++中的字符是以ASCII码表示的
   * ASCII码是最早的西欧那边企图用 7bit或8bit 也就是128或256个数来表示一些字符的包括a-Z 0-9 以及一些特殊符号等
   * 常用的:
   *  0: 48 0x30 
   *  a: 97 0x61
   *  A: 65 0x41
   *  DEL: 127 0x7F 键盘上的按键
   * 
   * 
   * Unicode编码:
   *  最初的目的就是把世界上的文字都映射到一套字符空间中
   *  Unicode字符集有三大种编码方式, 分成五小种编码方式
   *    1. UTF-8
   *      1 byte表示字符, 可以兼容ASCII码
   *      特点是存储效率高, 变长(可以使用多个字节来表示字符, 比如表示汉字) 一般可以用4byte表示43亿个字符
   *      但虽然可以变长, 但是仍然以1 字节作为一个单位 只是对不同的字符用不同的长度的单位表示。
   *      UTF-8编码至少有一个字节，从首字节就可以判断一个字符的UTF-8编码有几个字节。
   *      如果首字节以0开头，肯定是单字节编码，
   *      如果以110开头，肯定是双字节编码，
   *      如果是1110开头，肯定是三字节编码，以此类推。
   *      除了单字节外，多字节UTF-8码的后续字节均以10开头。
   *      
   *      所以1～4字节UTF-8编码看起来是这样的：
   *       0xxxxxxx
   *       110xxxxx 10xxxxxx
   *       1110xxxx 10xxxxxx 10xxxxxx
   *       11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
   *
   *      单字节可编码的Unicode范围：\u0000~\u007F（0~127）
   *      双字节可编码的Unicode范围：\u0080~\u07FF（128~2047）
   *      三字节可编码的Unicode范围：\u0800~\uFFFF（2048~65535）
   *      四字节可编码的Unicode范围：\u10000~\u1FFFFF（65536~2097151）
   * 
   *      127、2047、66535、2097151这几个临界值怎么来的？
   *      因为UTF-8编码含有用于标识编码的0、110、1110等，
   *      所以1～4个字节的UTF-8编码有效位数分别为7、11、16、21。
   *      
   *      比如:
   *       字符    ASCII            Unicode                       UTF-8
   *        A    01000001     00000000 01000001                 01000001
   *        中      无         01001110 00101101        11100100 10111000 10101101
   *       因为UTF-8每个字节前面几位都是固定的 所以把前面固定的几位干掉之后拼起来 剩下的就是Unicode编码
   * 
   *      然后UTF-8之所以没有大小端的问题 是因为程序运行时候已经告诉它是要以utf-8的方式编码了
   *      又因为utf-8的编码方式是以固定头部开头的
   *      比如 char zhong = 中;
   *      中这个字的utf-8编码是 11100100 10111000 10101101
   *      程序碰到这个字会挨个去读, 如果是大端表示的话 那就按着 11100100 --》 10111000 --》 10101101 这个顺序
   *      没有任何问题, 如果是小端的话, 就算按照 10101101 --》 10111000 --》 11100100 这种顺序读的话
   *      在程序已知是UTF-8编码的情况下, 当读到第一个 10101101 发现它的开头不是 0 | 110 | 1110 | 11110 
   *      然后就直接继续往下读 当读到最后一个 11100100 的时候才发现这个才是头 于是把之前的拼到它后头
   *      所以 UTF-8 不存在大小端这种字节序的问题
   * 
   *      UTF-8的缺点就是由于它是变长的, 所以不利于内部随机访问, 也就是效率较低
   * 
   *    2. UTF-16: { UTF-16BE(big-endian), UTF-16LE(little-endian) }
   *      特点是定长两字节 方便内部随机访问 但是有字节序的问题
   *    3. UTF-32: { UTF-32BE(big-endian), UTF-32LE(big-endian) }
   *      特点是定长两字节 方便内部随机访问 但是有字节序的问题
   */
  char c1 = 0; // 0x00
  char c2 = '\0'; // 0x00
  char c3 = '0'; // 0x30 ASCII码中的字符'0'是0011 0001 对应到16进制就是0x30
  cout << c1 << endl; // 啥也不输出
  cout << c2 << endl; // 啥也不输出
  cout << c3 << endl; // 0
  cout << int(c3) << endl; // 48 因为 '0' 在内存里是 0x30 转成10进制就是48
  return 0;
}
