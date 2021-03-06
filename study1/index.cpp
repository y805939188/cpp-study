// #include "stdafx.h" 这个是在windows系统下自动创建的一个头文件 便于做项目管理用的
#include "iostream" // 这个是系统库
#include <assert.h> // assert是断言的意思 可以不使用cout endl这种输出 可以直接用这个assert做断言
#include <vector> // 面向对象的动态数组库 系统自带 要和下面的std命名空间一块儿用
#include <string.h> // 用于操作string的库
#include <string> // 不引入string可以 因为引入了iostream 这个里头包含了string
#include <memory> // 这个库里头有auto_ptr智能指针
using namespace std; // 这个是系统库中包含的命名空间
// 其实printf也可以输出 只是printf是c语言中的输出方法

// command + R 或者 + T是快捷键的编译
int main(void) {
  int arr0[5] = { 1,2,3,4,5 };
  cout << *arr0 << endl; // 直接输出arr0的话是一个地址 *arr0的会指向arr0的第一个
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

  // 默认初始化,不带参数的构造函数初始化
  vector<int> vec1;
  vec1.push_back(5);
  cout << vec1[0] << endl; // 5
  // 带参数的构造函数初始化
  vector<int> vec2(10); // 初始化10个默认值为0的元素
  vector<int> vec3(10, 1);// 初始化10个值为1的元素
  cout << vec2[8] << endl; // 0 因为每项都是0
  cout << vec3[8] << endl; // 1 每项都是1

  // 通过数组地址初始化
  int test[5] = { 1, 2, 3, 4, 5 };
  vector<int> vec4(test, test + 5);
  cout << vec4[4] << endl; // 5

  // 通过同类型的vector进行初始化
  vector<int> vec5(10, 1);
  vector<int> vec6(vec5);
  cout << vec6[5] << endl; // 1

  // 通过迭代器进行初始化
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
   * 
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
   *       特点是定长两字节 方便内部随机访问 但是有字节序的问题
   *       所以不能作为外部编码, 意思就是假设当进行网络传输的时候 必须还得先知道到底是大端还是小端
   *       比如 "h" 这个字符
   *         会表示成 00 68 或 68 00 (一个大端 FF, 一个小端 FE)
   *         utf-16固定是两字节的方式
   *    3. UTF-32: { UTF-32BE(big-endian), UTF-32LE(big-endian) }
   *       特点是定长四字节 方便内部随机访问 但是有字节序的问题
   *       而且太占地儿
   * 
   *    一般编码错误的根本原因 在于编码方式和解码方式不统一
   * 
   *    注意: windows 文件可能有BOM(byte order marker) 就是对字节序的一个标识之类的, 如果要在其他平台使用可以去掉BOM
   * 
   * 
   *    Unicode和UTF-8之间的关系
   *      简单地说, Unicode是一个字符集, 里面给每个字都定义了一个唯一的编号(码位)
   *      是一个字符编码的标准规范, UTF8之类的是针对这个规范的实现
   *      而UTF-8/16/32之类的是对这些码位进行编码的方式
   *      比如直接你可以直接把这些码位转成二进制存进电脑去
   *      像UTF8这种编码方式 比如存个“中”字 去Unicode表里头找它对应的码位
   *      然后把它的码位按照上面记录的方式 编码成1到4个字节存到内存中
   *      https://www.zhihu.com/question/23374078
   */
  char c1 = 0; // 0x00
  char c2 = '\0'; // 0x00
  char c3 = '0'; // 0x30 ASCII码中的字符'0'是0011 0001 对应到16进制就是0x30
  cout << c1 << endl; // 啥也不输出
  cout << c2 << endl; // 啥也不输出
  cout << c3 << endl; // 0
  cout << int(c3) << endl; // 48 因为 '0' 在内存里是 0x30 转成10进制就是48

  /**
   * 字符串的指针表示方法 
   */
  char dingStr2[] = { "helloworld" }; // 这样也可以
  char dingStr3[11] = { "helloworld" };
  char *dingStr1 = "helloworld"; // dingStr 是指针变量 这个相当于指向了一个字符串的常量
  // char dingStr2 = "a"; // 这样不可以
  // 对于带*的那种指针变量 是存在内存的堆里 而上面那两种是存在栈区
  // for (int index = 0; index < 10; index++) { // 不应该对那个 '\0' 的结束符做操作
  //   // c++中的＋1不是js里那种简单的字符串加数
  //   // 而是对内存中的二进制进行 +1 相当于说 "h" 字母的二进制 +1 了, 然后对应到ASCII表里应该就是i
  //   dingStr2[index] += 1;
  //   cout << dingStr2[index] << endl;
  // }
  cout << dingStr1[0] << endl; // h
  cout << (dingStr1) << endl; // helloworld
  cout << (dingStr1 + 1) << endl; // elloworld
  // for (int index = 0; index < 8; index++) { // 不应该对那个 '\0' 的结束符做操作
  //   dingStr1[index] += 1; // 这个会报错的 指针所指向的区是不可改的 上面那个是个常量
  //   cout << dingStr2[index] << endl;
  // }

  // 但是当指针直接指向了一个栈中的区的地址时候可以改
  char dingStr4[11] = { "helloworld" };
  char *dingStr5 = dingStr4;
  for (unsigned int index = 0; index < 10; index++) {
    dingStr5[index] += 1;
    cout << dingStr5[index] << endl;
  }

  char dingStr6[11] = "helloworld";
  char dingStr7[11] = "helloworld";
  char ding[] = "dddd";
  cout << ding << endl; // dddd
  cout << dingStr6 << endl;
  cout << (dingStr4 == dingStr6) << endl; // 0
  cout << (dingStr7 == dingStr6) << endl; // 0
  // dingStr6 = dingStr7; // 这个会报错 左值不允许改
  dingStr5 = dingStr7;
  cout << dingStr5[0] << endl; // h 但是指针可以改
  // 相当于 一个正常变量本身不可改 但是这个变量指向的区内的东西可改
  // 比如 char ding1[10] = "niubi" 这个ding1不能改 但是 ding[index] 可改
  // 而对于指针变量 本身可改 但是所指向的内容不一定能改
  // 比如 char *ding2 = "niubi" 这种情况下 ding2[index] 不能改
  // 但是 ding 本身可以指向别的变量比如 ding1 = ding2 然后ding1[index] 就可改了
  char dingStr8[] = "ding";
  cout << strlen(dingStr8) << endl; // 4
  char dingStr9[] = "ding2";
  cout << strcmp(dingStr8, dingStr9) << endl; // s1 < s2 返回小于0 s1 > s2 返回大于0 按ASCII 从左至右挨个字符比较大小 知道遇到不一样的或者 /0
  strcpy(dingStr8, dingStr9); // 把后面的一个个拷贝到前一个字符串中
  cout << dingStr8 << endl; // ding2
  strncpy(dingStr8, dingStr9, 2); // 把字符串dingStr9中的前2个拷贝到dingStr8中
  // strcat(dingStr8, dingStr9); // 将字符串dingStr9拼接到dingStr8后面
  strchr(dingStr8, 'n'); // 字符串n第一次在dingStr8中出现的位置
  strstr(dingStr8, dingStr9); // 字符串dingStr8中dingStr9第一次出现的位置
  // 以上的api有的不安全 因为比如拼接的时候可能前面的字符串内存容量不够
  // 比如上面那个strcat拼接的方法,
  // 如果前面的容量只有10 加上后面的溢出的话 就会把这个字符串在内存中后面的位置给覆盖,
  // 如果被覆盖的位置还有别的逻辑的话, 那肯定会出bug
  // 所以开发时候可以开启一个 "宏" 来允许使用这种api
  // 同时还有一些比较安全的方法可以使用
  char dingStr10[16] = { "a" };
  char dingStr11[16] = { 0 };
  cout << strlen(dingStr10) << endl; // 1
  cout << strlen(dingStr11) << endl; // 0
  // for 循环定义index的时候 前面最好加上unsigned表示无符号数
  // 否则的话回报警告说用一个有符号的作为数组下标
  signed short aa = 65535;
  cout << (aa + 2) << endl;

  // 以下的是安全版本
  // strlen_s(dingStr8);
  // strcpy_s(dingStr8, 10, dingStr9);
  // strcat_s(dingStr8, 10, dingStr9);


  /**
   * c++标准库中提供了string类型专门表示字符串
   * #include <string>
   * using namespace std;
   * 可以更方便和安全的管理字符串
   */
  string s1; // 会有一些默认的资源分配原则 capacity默认是15
  string s2 = "helloworld";
  string s3("helloworld");
  string s4 = string("hellowworld");
  cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << endl;
  cout << s2.length() << endl; // 10
  cout << s2.size() << endl; // 10
  cout << s2.capacity() << endl; // 22
  cout << ( s2 == s3 ) << endl; // 1
  string s5 = "ding";
  string s6 = "1";
  cout << s5 + s6 << endl; // ding1

  /**
   * https://blog.csdn.net/z_qifa/article/details/77744482
   * 详解sizeof、strlen、length、size的区别
   */


  /**
   * const 关键字修饰离他近的
   * 比如:
   *  const char* ding = "xxxx" 这个它修饰char*
   *  char* const ding = "xxxx" 这个它修饰ding 
   */



























  /**
   * 指针
   *  
   * 
   *  
   */

  int test1 = 11;
  // int dd = &test1; 这样会报错
  int* test2 = &test1;
  cout << &test1 << endl; // 可以打印出地址
  cout << test2 << endl; // 可以访问地址
  cout << *test2 << endl; // 11 可以访问这个地址对应的值
  // 加入存了个数 float test = 3.14f;
  // 这个test存到内存中是一串数, 但是如果按照整形翻译的话肯定不会得到3.14
  // 那为啥它就能打印出3.14呢
  // 因为这个是编译器决定的, 编译器从内存中拿到这串数 然后会根据记录下来的类型
  // 去做转换 根据IEEE 转换成浮点数

  // int var = 6;
  // var是左值 在内存中占有确定的内存空间
  // var + 1 是右值 因为是表达式 表达式只是个临时的结果 只是在计算的周期驻留在临时寄存器中

  /**
   * 一般类型指针 T*
   *    int* A = 1
   *    double* B = 1.0
   *    char* C = 'a';
   *  
   *    cout << (*A) << endl;
   * 
   *    上面和下面的*是不一样的 上面指的是定义一个指针变量
   *    下面指的是取这个指针变量对应的值
   */
  
  // char ddd = 'bkjhgssssa';
  // cout << ddd << endl; // 只会输出a

  /**
   * 指针的数组和数组的指针
   *  指针的数组 T* t[] 指一个数组 数组里头每个都是一个指针
   *  数组的指针 T (*t)[] 指一个指针 这个指针指向了一个数组
   * 
   */

  // const 修饰规则
  // 如果有左边 就修饰离他最近的左边
  // 如果没左边 就修饰离他最近的右边
  char const *niubi1 = "abc"; // 相当于const修饰左边的类型
  niubi1 = "bcd"; // 所以该指针可以指向别人
  // niubi1 = 123; 会报错 但是指向的内容一定不能变
  char* const niubi2 = "abc"; // 左边是指针 说明const修饰指针
  cout << niubi2 << endl; // abc
  // niubi2 = "bcd"; 会报错 所以指针的指向不可变
  char const* const niubi3 = "abc"; // 俩const 第一个修饰左边的类型 第二个修饰左边的指针
  // niubi3 = "123"; 会报错 所以说明指针的指向不允许改变 同时里边的类型也不许改变
  const char* niubi4 = "abc"; // const右侧最近的是类型 所以修饰类型
  niubi4 = "bcd";
  // niubi4 = 123; 会报错
  cout << niubi4 << endl;

  // char const *niubi5 = "abc";
  // char* const niubi6 = "abc";
  // char const * const niubi7 = "abc";
  // char const* const niubi8 = "abc"; 
  // char * const const niubi9 = "abc";
  // const char* niubi10 = "abc";


  /**
   * 指针变量 在内存中存放的形式 实际就是存一个地址
   * char ding1[] = { "ding" };
   * ding1的地址假设是 0x00111111 然后指向了一个内存中的 "ding"
   * char const* ding2 = "ding";
   * ding2在内存中的存放形式 其实就是 0x00111111 也指向了 "ding"
   * 因为编译器会做一个优化 发现内存中已经有一块儿地方是 ding 了 就复用了
   * char* const ding3 = ding1;
   * ding3的存放形式 也会是 0x00111111
   * char const* const ding4 = "ding"
   * 这个ding4的存放形式也是一个地址 但是它肯定就不是0x00111111了 因为存放形式不一样 它是绝对不允许变的
   * 
   * 其实上面的ding2和ding3就会产生问题
   * 因为ding2和ding3都是指针 且都指向了ding1
   * 但是ding2是类型不能变 指针能变
   * 而ding3是类型能变但是指针不能变
   * 也就是说直接对ding2[0] = 1是不行的
   * 但是ding3[0] = 1却可以
   * 最后ding1 ding2 和 ding3 的[0]都变成1了
   * 这样就产生了ding2虽然不让变 但是却变了的问题
   * 
   */

  /**
   * 指向指针的指针
   * 也叫二级指针
   */
  int ding1 = a;
  int* ding2 = &ding1;
  int** ding3 = &ding2; // 相当于 ding2 可以间接访问ding1 ding3可以间接访问ding1
  int*** ding4 = &ding3; // 相当于 int(*(*(*ding4))) = &ding3 这么写也不报错 从里向外逐层求值
  cout << (&ding1 == ding2) << endl; // 1 这俩一样
  cout << ding2 << endl; // ding2 虽然自己是个指针
  cout << &ding2 << endl; // 但是它这个指针自己本身也可以有个指针指向他
  cout << (ding3 == &ding2) << endl; // 1
  cout << ding4 << endl;


  /**
   * 未初始化和非法指针
   *  int *a;
   *  *a = 12;
   *  未初始化的指针 就会指向一个未知的区域
   *  这个行为虽然可以 但是不能这么用, 因为很危险
   *  运气好的话定位到一个非法地址 程序会出错直接终止
   *  运气不好的话定位到一个可访问的地址 并且把这个地址修改的话
   *  就会出现预料不到的问题
   * 
   *  如果一个指针还没有被初始化 那就一定不要用它
   * 
   * 
   * 
   *  NULL指针 表示不指向任何东西
   *  int* a = NULL;
   *  一个指针如果我们不想用了或者它没用了 就让他指向NULL就行
   *  或者初始化一个指针的时候不知道该让他指向谁的时候 就让他指向NULL
   *  
   *  在对一个指针进行间接引用之前 应该先判断一下他是否是NULL
   * 
   * 
   * 
   * 野指针
   *  指向垃圾内存的指针 if等判断对它不起作用
   *  啥是辣鸡呢? 
   *  一般有三种
   *    1.指针变量没有初始化
   *    2.已经释放不用的指针没有置为NULL, 如delete和free之后的指针
   *    3.指针操作超越了变量的作用范围
   *      这第三个是啥意思呢
   *      就是当一个指针 指向了某个有生命周期的作用域的时候
   *      比如指向了一个 {  xxxxx  }
   *      当这个类似于对象的东西使用完了那他的内存被释放了
   *      但是如果仍然有个指针指向他的时候
   *      当别人再复用这块儿内存的时候 那这个指针就不知道指向的到底是个啥了
   * 
   * 对于没有初始化的、不使用的、或者超出作用域范围的 都应该置为NULL
   */

  int i1 = 2147483647;
  int i2 = 0b10000000000000000000000000000000;
  //       0b11111111111111111111111111111111;
  //       0b10000000000000000000000000000000;
  cout << (i1 + 1) << endl; // -2147483648
  cout << i2 << endl;
  // 计算机中采用补码来存放数字
  // 正数的补码还是他自己
  // 所以2147483647 -> 0b01111111111111111111111111111111;
  // 由于默认int类型有符号 所以第一位表示+;
  // 加上1之后也就剩是2147483648 -> 0b10000000000000000000000000000000;
  // 0b10000000000000000000000000000000是一个补码 第一位是1表示 -;
  // 也就是-0000000000000000000000000000000 = -0;
  // 由于正数最大有31位 2**31 = 2147483648;
  // 算上0的话 最大只能表示到2147483647;
  // 0已经由0b00000000000000000000000000000000表示了;
  // 所以就默认让最后剩下的0b10000000000000000000000000000000表示最小的一个数
  // 也就是 -2147483648

  /**
   * 10 - 8 = 10 + (-8) = 2;
   *  10: 0b00001010
   *  -8: 0b10001000
   *  0b00001010 + (0b10001000) 10 + (-8的原码)
   *  -> 0b00001010 + (0b11110111) 10 + (-8的反码)
   *  -> 0b00001010 + (0b11111000) 10 + (-8的补码)
   *  -> 0b100000010 得到一个肯定溢出一位的二进制
   *  -> 0b00000010 舍弃掉溢出的那位
   *  -> 2 得到最终结果
   * 
   */

  /**
   * 指针不管啥类型的 都是默认的4字节 
   */

  // char aaa = 'a';
  // char ccc = 'b';
  // char* bbb = &aaa;
  // bbb = &ccc; 这个可以
  // &ccc = xxx 不可以
  char aaa = 'a';
  char* bbb = &aaa;
  char ddd = *bbb;
  cout << ddd << endl; // a 会得到实际上aaa的值
  cout << (*bbb + 1) << endl; // 98 *bbb是取值 得到a 然后 +1 是用a的utd8或ascii码+1得到b (98)
  // cout << *(bbb + 1) << endl; // bbb是一个地址 +1 之后这块地址加个*表示取值 会往右边走4字节

  char eee = 'a';
  char* fff = &eee;
  *fff = 'b';
  cout << *fff << endl; // b *fff 就相当于 eee 这个变量
  cout << eee << endl; // b

  // 左值是必须有办法能够获取到明确地址的 右值是不能获取到明确地址的
  
  char* ggg = ++fff; // 所以他是先加 再赋值
  /**
   * ++fff 在汇编中长这样
   *   (addr)    (act)       (执行动作)
   *  003716E2    mov    eax, dword ptr [fff] // eax是寄存器的一种 dword ptr [fff] 指的是把 fff 移动到eax这个寄存器中
   *  003716E5    add    eax, 1               // 在eax寄存器中给fff +1
   *  003716E8    mov    dword ptr [fff], eax // 从eax中把 fff 移动回去
   *  003716Eb    mov    ecx, dword ptr [fff] // 把fff移动到 ecx 中 ecx也是寄存器的一种
   *  003716EE    mov    dword ptr [ggg], ecx // 从 ecx 中移动到 ggg
   */
  char* hhh = fff++; // 然后他是先赋值 再加
  /**
   * fff++ 在汇编中长这样
   *   (addr)    (act)       (执行动作)
   *  003716E2    mov    eax, dword ptr [fff] // eax是寄存器的一种 dword ptr [fff] 指的是把 fff 移动到eax这个寄存器中
   *  003716E5    mov    dword ptr [ggg], eax // 把eax中的给移动到 ggg
   *  003716E8    mov    ecx, dword ptr [fff] // 移动 fff 到 ecx 中
   *  003716Eb    add    ecx, 1 // 在 ecx 中给它 +1
   *  003716EE    mov    dword ptr [fff], ecx // 从 ecx 中移动到 fff
   */
  /**
   * fff-- 和 --fff 同理 
   */
  /**
   * ++fff 得到的只是一个地址值的副本 所以是右值
   */

  /**
   *  *++fff / *fff++ 等于 *(++fff)/*(fff++)
   */

  /**
   * c = a+++b 等于 a++ +b
   * c = a++++b 等于 a++ ++b
   * ++*++a 等于 (++(*(++a)))
   */

  int number0 = 1;
  int* number1 = &number0;
  // 首先number1是个指针 指针++之后得到该指针的下一个位置 然后*号在右值时表示取值 也就是把number1下一个位置的值取出来了 之后这个值再++
  int number2 = ++*++number1;
  cout << number2 << endl;


  /**
   * 栈: 先进后出
   * 队列: 先进先出
   */
 
  // 假设有如下函数
  // int p1 = 0; 全局变量             (GVAR)全局初始化区
  // int* a; 全局变量                 (bss)全局未初始化区
  // int main() {                    (text)代码区
  //   int b = 1;                    (stack)栈区变量
  //   char s[] = "abc";             (stack)栈区变量
  //   int* p2 = NULL;               (stack)栈区变量
  //   char* p3 = "123456";          123456\0 在常量区, p3在(stack)栈区
  //   static int c = 0;             (GVAR)全局(静态)初始化区 static表示在全局范围内可见 所以c在全局区
  //   p1 = new int(10);             (heap)p1变量本身在栈区 指向的内容堆区变量 new这个语法会产生新的堆区
  //   p2 = new int(20);             (heap)p2变量本身在栈区 指向的内容堆区变量
  //   char* p4 = new char[7];       (heap)p4变量本身在栈区 指向的内容堆区变量
  //   strcpy_s(p4, 7, "123456");    (text)代码区
  //
  //   return 0;                     (text)代码区 汇编指令都在专门的代码区
  // }

  char s[] = "abc";
  cout << s << endl;
  cout << &s << endl;

  /**
   * 
   * new返回的是指针, 而java中返回的是引用, 所谓的引用就是类的一个别名
   * 假设有个类Test
   * 在C++中你执行了Test *t=new Test(); 电脑实际上是分成好几步完成的
   * 1. 要在堆中申请类的内存 (new 运算符实际是调用malloc函数来分配内存的,调用new之前会把类的大小当作参数传入)
   * 2. 申请完内存后，把类在堆中的地址 存入寄存器EAX中 (一般是EAX存放返回值，不同编译器可能不同的)
   * 3. 然后把EAX中存放的地址放到变量 t 中, 这样类在内存的模型就创建好了,
   * 4. 调用构造函数，对在堆中创建的内存模型进行初始化，虚函数表的初始化等操作,这样一个对象就创建好了,
   *    概括来说你一个new X (), 语句实际的效果就是先申请了内存,
   *    然后调用构造函数对申请了的内存进行初始化,
   *    这两步操作返回值都是类在内存中的地址, 通过寄存器EAX返回给调用者
   */

  // c++中 new 一个东西 返回的是指针
  // int p1 = new int(10); // 会报错
  int* p1 = new int(10);
  // char p4 = new char[7]; // 会报错
  char* p4 = new char[7];
  cout << p4 << endl; // 打印出一个地址

  /**
   * 变量名之所以能转化成地址
   * 是因为编译器在处理c++代码的时候 会建立一张符号表 比如 int a 会把a放进这张符号表中 然后根据表中的映射找到地址
   */

  
  /**
   * 动态分配资源 -- 堆
   * 
   *  c++中可以分配某一个大小的内存块
   *  也可以释放一个之前分配的内存块
   *  
   *  但是没有主动的垃圾回收
   * 
   */
  

  /**
   * RAII (Resource Acquisition Is Initalization)  资源获得即初始化
   * 
   * 依托于栈和析构函数 来对所有的资源 包括堆内存在内进行管理
   * 对RAII的使用 使得c++不需要类似于JAVA那样的垃圾收集方法
   * 
   * RAII有些比较成熟的智能指针代表 如: std::autop_ptr和boost:shared_ptr
   * 
   */


  /**
   * 变量的对比
   * 
   *                              栈区(stack)                                    堆区(heap)
   * 
   * 作用域                 函数体内, 可以理解成一个 {} 内                整个程序范围内, 由 new, malloc 开始
   *                                                                     delete, free 结束
   * 
   * 
   * 
   * 编译期间大小确定         在编译阶段就可以确定 编译器在做                变量大小范围不确定 需要运行期确定
   *                           语法检查的时候就能知道 
   * 
   * 
   * 
   * 大小范围                win系统默认栈大小是1M, linux常见             一般不做限制 由虚拟内存的总大小决定
   *                           默认栈大小是8M或10M
   * 
   * 
   * 
   * 内存分配方式             地址由高到低减少                            地址由低到高增加
   * 
   * 
   * 
   * 内容是否可变             可变                                      可变
   * 
   * 
   * 
   */


  /**
   * 变量的对比
   * 
   *                              全局静态存储区                                  常量存储区
   * 
   * 存储内容                     全局变量 静态变量                                   常量
   *                                                                     
   * 
   * 
   * 
   * 编译期间大小确定                    确定                                         确定
   *                           
   * 
   * 
   * 
   * 大小范围                win系统默认栈大小是1M, linux常见             一般不做限制 由虚拟内存的总大小决定
   *                           默认栈大小是8M或10M
   * 
   * 
   * 
   * 内容是否可变                        可变                                       不可变
   * 
   * 
   * 
   */

  /**
   * 释放内存的方法
   * 比如:
   *  int ding1 = new int(10);
   *  char ding2[] = new char[7];
   * 
   *  if (ding1 != NULL) {
   *    delete ding1;
   *    ding1 = NULL;
   *  }
   * 
   *  if (ding2 != NULL) {
   *    delete[] ding2;
   *    ding2 = NULL;
   *  }
   * 
   */

  /**
   * 内存泄漏
   * 堆内存中的数据要有程序员主动释放 如果释放不及时
   * 可能就泄露
   *  
   * 
   */


  /**
   * 指针虽好 但是容易发生危险
   * 
   * 更安全的指针 - 智能指针
   * 不适用指针 使用更安全的方式 - 引用
   * 
   */

  /**
   * c++中有四种常用的智能指针
   * 
   * unique_ptr shared_ptr weak_ptr auto_ptr(在c++17中被废弃了)
   * 
   * 1. auto_ptr
   *  可以指向一个对象(类或者int或者char等等都行), 在auto_ptr指针被销毁时 所指向的那个对象自动被delete
   *  如果一个auto_ptr指向了某个对象 之后又有另外一个auto_ptr指向了这个对象
   *  那之前的那个auto_ptr就会指向nullptr(失效, 不是NULL)
   *  之所以不是NULL 是因为NULL是属于C语言的遗留 并且NULL有二义性 它可以指指针是个NULL也可以只普通数据是NULL
   *  所以这里一般规范一些就用nullptr表示指针为空
   * 
   */

  // {
  //   auto_ptr<int> p1 = new int(10); // 不晓得为毛这里会报错 说auto_ptr未定义
  //   cout << *p1 << endl; // 10
  //
  //   auto_ptr<string> languages[5] = {
  //     auto_ptr<string>(new string("a")),
  //     auto_ptr<string>(new string("b")),
  //     auto_ptr<string>(new string("c")),
  //     auto_ptr<string>(new string("d")),
  //     auto_ptr<string>(new string("e")),
  //   }
  //
  //   // 这里可以正常打印
  //   for (int i = 0; i < 5; i++) {
  //     cout << *languages[i] << endl;
  //   }
  //
  //   // 这里将languages[2]的指针让渡给了p2
  //   auto_ptr<string> p2;
  //   p2 = languages[2];
  //
  //   // 这里顶多打印到前两位 当打印到第三位时候 因为指针被让渡了 就会报错
  //   for (int i = 0; i < 5; i++) {
  //     cout << *languages[i] << endl;
  //   }
  // }
  

  /**
   * unique_ptr 专属智能指针
   * 它是专属所有权 只能被一个对象持有 不支持赋值和复制
   * 
   * unique_ptr 不允许复制和赋值 但是允许移动(move)
   * 能够转移所有权
   * std::move()
   * 
   */

  // auto是自动类型推导 c++11 以上支持 w 返回的是一个unique_ptr的智能指针 会在堆中开辟一块儿空间
  // auto w = std::make_unique<int>(10);
  // cout << *(w.get()) << endl; // get会得到指针 得到指向刚刚在堆中开辟的那块儿空间的指针 加*是把指针的值输出
  // auto w2 = w; // 这个会报错 因为unique_ptr不支持重新赋值
  // auto w2 = std::move(w); // w2会获得内存的所有权 w此时等于nullptr
  // cout << ((w.get() != nullptr) << endl;

  /**
   *
   * shared_ptr 可以共享的智能指针
   * 当创建了一个堆内存中的对象的时候 每有一个智能指针指向该对象的时候 就会在内部给引用计数+1
   * 当这个引用计数变成0了 就会释放该内存
   * 但是也有个问题 就是循环引用的问题 比如A中引用了B  B中引用了A 这俩想释放都得等对方先释放
   * 就特么锁在这儿了 从而造成内存泄漏
   * 
   * 然后就出现了一种叫做 weak_ptr 的智能指针
   * weak_ptr和shared_ptr一起用的
   * A可以使用shared_ptr指向一个对象 B可以使用weak_ptr也指向同一个对象
   * 但是只有使用了shared_ptr的A会对该对象的引用计数 +1 使用weak_ptr的B不会给引用计数+1
   * 同时如果A被干掉的话 那么使用了weak_ptr的B也会被直接干掉
   * 因为B主要是依附于A的 可以使用A的一些能力 相当于一个观察者模式
   * 
   */

  {
    auto wA = shared_ptr<int>(new int(20));
    {
      auto wB = wA;
      cout << (wB.get() != nullptr ? *wB.get() : -1) << endl; // 20
      cout << (wA.get() != nullptr ? *wA.get() : -1) << endl; // 20
      cout << wA.use_count() << endl; // 2
      cout << wB.use_count() << endl; // 2
    }
    cout << wA.use_count() << endl; // 1 因为出了上边的那个花括号 wB 就被干掉了
  }

  // auto wAA = std::make_shared<int>(30);
  // auto wBB = std::move(wAA);
  // wAA 就会指向 nullptr
  // wBB 就变成了那个指针
  // wAA.use_cout() // 0
  // wBB.use_cout() // 1




  /**
   * c++ 中的引用
   * 引用是一种特殊的指针 不允许修改的指针
   * 相当于说有个指针指向了内存中的这块儿区域 那就不允许再让它指向别的区域
   * 
   * 使用普通指针有什么问题:
   *  1. 空指针
   *  2. 野指针
   *  3. 不知不觉改变了指针的值 却继续使用
   * 
   * 使用引用 则可以:
   *  1. 不存在空引用
   *  2. 必须初始化
   *  3. 一折引用永远指向它初始化的那个对象
   * 
   * 引用的基本使用 可以认为是指定变量的别名
   * 使用时可以认为就是比变量本身
   */

  int dingye = 1, liuye = 233;
  int& dingye2 = dingye;
  dingye2 = 666;
  cout << dingye << endl; // 666
  cout << dingye2 << endl; // 666
  dingye2 = liuye;
  cout << dingye << endl; // 233
  cout << dingye2 << endl; // 233

  /**
   * 有了指针为什么还用引用
   *   使用了支持函数运算符重载
   *  
   * 有了引用为什么还用指针 
   *   为了兼容C语言
   */


  /**
   * switch 和 if 的性能
   * 
   * 当分支比较少的时候无差别
   * 当多了 switch 效率高
   * 
   * 因为翻译成汇编之后
   * if 的逻辑为:
   *  当不满足时候会跳转到下一个地址
   *  当满足会执行当前的逻辑
   *  相当于一个二叉树
   *         条件1
   *          |
   *     |             |
   *    满足        不满足条件2
   *                   |
   *          |                     |
   *         满足                不满足条件3
   *                                |
   *                               ...
   * 
   * 
   * 而 switch 的汇编大概是
   * 1. 先把要判断的条件放进exa寄存器
   * 2. 然后判断条件是否和case1想等
   * 3. 如果想等直接跳转到case1对应的代码块
   * 4. 如果不想等就判断和case2是否相等
   * 5. 以此类对
   * 所以相当于是一开始就构建了一张表 一张条件表
   * 一次从表里找到合适的条件然后进行跳转
   * 
   */



  /**
   * 自定义结构 -- 枚举
   * 
   *  使用 #define和const可以创建符号常量 使用enum不仅可以创建符号常量
   *  还能定义新的数据类型
   * 
   */

  // 引妞闷儿 今天刚知道原来它这么读啊
  enum myWeek { Monday, Tuesday, Wednesday, Thuersday, Friday, Saturday, Sunday }; 
  myWeek weekday;
  weekday = Monday;
  weekday = Tuesday;

  // 打印的话会得到它的索引
  cout << weekday << endl; // 1
  weekday = Wednesday;
  cout << weekday << endl; // 2
  weekday = Monday;
  cout << weekday << endl; // 0

  // weekday = 1; // 会报错

  // 可以强制类型转换
  weekday = myWeek(1);
  cout << weekday << endl; // 1
  weekday = myWeek(2);
  cout << weekday << endl; // 2
  weekday = myWeek('a');
  cout << weekday << endl; // 97

  // enum 内部的类型是int类型
  int weekNum = Monday;
  cout << weekNum << endl; // 0

  enum myEnum { Ding1 = 'a', Ding2 = 666 };

  myEnum dingEnum;
  dingEnum = Ding1;

  cout << dingEnum << endl; // 97
  dingEnum = Ding2;
  cout << dingEnum << endl; // 666


  /**
   * 自定义类型 -- 结构体与联合体
   * 结构体 struct(struction)
   * 联合体 union
   */

  // 联合体
  union Score { // 联合体内部的东西使用共同的一块儿空间
    double sc;
    char level;
  };

  struct Student { // 结构体
    char name[10];
    int age;
    Score s; // 联合体
  };

  cout << sizeof(Score) << endl; // 8
  cout << sizeof(Student) << endl; // 24

  Student d1;
  d1.age = 18;
  d1.s.level = 'a';
  // d1.name = 'ding'; // 这样会报错 因为 char name[] name是个数组名字 不能作为左值
  char name[10] = "ddd";
  // char* name2 = &name; // 会报错的
  cout << *name << endl; // d
  cout << name << endl; // ddd
  // strcpy_s(d1.name, 'ding'); // 所以想给d1.name 赋值得这么赋


  return 0;
}
