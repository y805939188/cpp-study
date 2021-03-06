#include "iostream"
using namespace std;

// char这个类型代表的是字符型
// 当定义一个char型变量 系统为其分配1个字节的空间，
// 这个空间内只够存放一个字符数值
// 而“abx”是一个字符串 包含隐式的结束符，它占四个字节的空间
// 一个字节的空间里面，你要放进去四个字节的值 当然放不下了
// 可以写作char a[]="abx"; 定义一个字符数组，把abx放进去
// 也可以写作char *a="abx" 这种写法并没有真正为abx开辟空间，
// 而是定义了一个指针，指向常量字符串的首地址，
// 所以这样写 a指向空间的值是不能改变的

int main(void) {
  // char ding0;
  // cout << ding0 << endl; // 输出一个 空
  // char *ding1 = "abc"; // abc
  // ding1 = "bcd";
  // cout << ding1 << endl; // bcd
  // char ding2 = 'a'; // ""双引号表示字符串 字符串长度会默认加上 \0 ''单引号表示字符 只占1字节
  // cout << ding2 << endl;

  // char* ding0 = "ding1";
  // ding0 = "sa";
  // ding0[0] = 'd'; // 会报错 因为ding0这个地址是一个常量地址
  // 它的汇编可能是这样 offset表示偏移量 指把在010xxxxxx取的string类型的
  /**
   * 
   *   其中那段 " string 'ding1' " 可能是编译器自己加上去的 只是为了开发调试的时候更方便
   *   实际汇编中可能没有这个 string "ding1"
   *   这块的汇编意思就是 直接把 0A88B30h 这个地址的值 赋值给 常量内存的 ding0 这个地址
   *   P.S. 0A88B30h是静态常量区
   *   00A81C75 mov     dword ptr [ding0], offset string "ding1" (0A88B30h)
   *   
   *   如果之后执行 ding0 = "xxx" 会直接把ding0的这个地址给改掉 相当于后面的 "xxx" 直接是一个新的地址
   * 
   */
  // 输出 d 如果直接 cout << ding0 << endl 就直接输出 "ding1"
  // 至于为啥不输出地址 因为 cout 的 << 有重载 会一直输出到 \0 结束符
  // cout << *ding0 << endl;

  // char ding1[] = "niubi";
  // ding1[0] = 'a'; // 可变 注意不能用双引号
  // 它的汇编可能长这样
  /**
   *   把0A88BD0h这个地址的值移动到eax寄存器
   *   (可以想象一下这个地址对应的那堆锁存器里头存着0和1 然后把这些锁存器中的0和1给挪到exa中)
   *   00A81C75  mov    eax,dword ptr [string "niubi" (0A88BD0h)]
   * 
   *   再从eax寄存器中把刚才那坨移动到ding1这个指针中(dword 表示4字节 ptr 表示指针)
   *   ding1 这个东西也是有个地址的 可能是在栈内存中有个对应的地址比如0x008ffxxx
   *   在把eax的东西移动到 ding1 之前 ding1这个地址里的东西应该是一堆的cccc 也就是烫烫烫 表示啥值也没有
   *   当这一步操作完了 ding1 那个地址里的值就变成了 "niub烫" 因为dword一次只移动4个字节 niubi 有5个字节
   *   00A81C7A  mov    dword ptr [ding1],eax
   * 
   *   之后cx表示循环 0A88BD4h 正好是 0A88BD0h 加了4字节之后的地址
   *   也就是把 ds寄存器的两字节移动到 cx 寄存器 cx寄存器用来做计数的
   *   00A81C7D  mov    cx,word ptr ds:[0A88BD4h]
   * 
   *   ebp表示偏移量寻址 应该可以理解成刚才那个ding1后边的按个"烫"的位置
   *   之后把 cx 寄存器的东西放进那个位置
   *   00A81C84  mov    word ptr [ebp-14h],cx
   * 
   *   至此 ding1 那个地址整个就变成了 "niubi"
   * 
   */

  /**
   * 由于[ ]比*优先级要高 因此a先与[n]结合 形成a[n]形式
   * 这显然是数组形式 它有n个元素
   * 然后和*结合 *表示此数组时指针类型的 每个数组元素都指向一个char型的变量
   * 
   * a[N] (*a)是一个指针有n个元素 每个元素为char型
   * 也就是a指向的对象是有4个char元素的数组 即a是指向一维数组的指针
   * 因记住，此时a只能指向一个包含n个元素的一维数组 a的值就是一维数组的起始地址 
   * 
   * 换句话说:
   *  char *a[N] 是声明了一个 指针数组 数组每个元素都是char *类型
   *  (数组每一位都是char类型的指针)
   * 
   *  char (*a)[N]是声明了一个 指向数组的指针 该指针指向一个数组 该数组具有N个char元素
   *  (类比 char a[N] 也是声明一个a指向一个数组 所以 (*a) 就是一个指针a指向数组)
   * 
   */

  // 
  // char* ding3[3] = { "a", "b", "c" };
  // char ding3[] = { "a", "b", "c" }; // 会报错 因为双引号表示一个字符串
  // char ding3[][3] = { "a", "b", "c" }; // 这样写也行 因为用双引号的话会被认为是字符串型的数组
  // char ding3[4] = { 'a', 'b', 'c' }; // 必须写成单引号形式 因为单引号才表示一个字符
  // ding3[0] = 'd'; // 可以修改
  // cout << 111 << ding3 << endl; // 输出abc
  /**
   * 汇编可能长这样
   * 就是直接把 ascii码中的 61 62 63(对应abc) 1比特 1比特地复制到ding3在栈内存的地址
   * 00C41C92  mov         byte ptr [ding3],61h  
   * 00C41C96  mov         byte ptr [ebp-27h],62h  
   * 00C41C9A  mov         byte ptr [ebp-26h],63h
   * 
   */

  // char (*ding4)[4] = &ding3;
  /**
   * 它的汇编大概长这样
   * 首先lea表示直接把 [ding3] 这个值赋值给eax 而不是去ding3对应的地址找存放的值
   * ding3实际就是个栈区中的内存地址 可能长这样 0x012ffxxx 之类的
   * 00981C9E  lea         eax,[ding3]
   * 
   * 然后把eax刚才那个ding3的地址值直接赋值给ding4这个四字节的指针
   * 00981CA1  mov         dword ptr [ding4],eax
   * 
   * 其实 char (*X)[N] = &Y 可以和 char *X = &Y 类比一下
   * char *X = &Y 就是直接把Y这个东西的地址赋值给 X
   * char (*X)[N] = &Y 中的Y实际也是直接把地址赋值给 X
   * 只不过上面的 Y 指向的是非数组类 下面的 Y 指向一个数组而已
   * 
   */
  // cout << 222 << ding4 << endl; // 输出一个地址

  // char* ding5[] = { "a", "b", "c" };
  /**
   * 它的汇编大概长这样
   * 就是直接把 a b c 的内存地址 mov 到ding5
   * 00981CA4  mov         dword ptr [ding5],offset string "a" (0988BD8h)  
   * 00981CAB  mov         dword ptr [ebp-44h],offset string "b" (0988BDCh)  
   * 00981CB2  mov         dword ptr [ebp-40h],offset string "c" (0988BE0h)
   * 
   * ding5 这个变量的地址可能就是这样 0x012ff8a0
   * 然后这个地址对应的内存空间就是 {0x00988bd8 "a", 0x00988bdc "b", 0x00988be0 "c"}
   * 之后ding5会默认指向这块儿空间的第一个 0x00988bd8
   */
  // cout << 333 << ding5 << endl; // 输出一个地址

  // char ding6[] = { "ding" };
  /**
   * 汇编大概这样
   * 首先把 0988BE4h 常量位置的 ding 这四个字节的值挪到eax中
   * 00981CB9  mov         eax,dword ptr [string "ding" (0988BE4h)]
   * 
   * 然后从eax中把 ding 这四个字节放到 ding6 这个地址中
   * 00981CBE  mov         dword ptr [ding6],eax
   * 
   * 然后把 0988BE4h 后面的 988BE8h 1个比特的值取出来 放进cl
   * 00981CC1  mov         cl,byte ptr ds:[988BE8h]
   * 
   * 最后把 cl 里的东西移动到 ebp-54h 这个地址
   * 00981CC7  mov         byte ptr [ebp-54h],cl
   * 
   * 之所以有最后两步 是因为 "ding" 字符串后面会默认有个 \0
   * 
   * 所以其实 char ding6[] = { "ding" } 和 char ding6[] = "ding" 是一毛一样的
   */
  // cout << 444 << ding6 << endl; // 输出ding

  // 总结 定义字符串大概有以下几种方式
  char test1[4] = { 'a', 'b', 'c' }; // test1在栈区 存的abc 相当于直接往test1这个地址中注入 a(61),b(62),c(63)
  char (*test2)[4] = &test1; // test2在栈区 存的test1的地址 char test1[] = "abc" 这样也可以 相当于直接往test2这个地址中注入test1的地址
  char* test3 = "abc"; // test3在堆区 直接把堆区中的某个地址中的"abc"注入到test3
  char* test4[] = { "abc" }; // test4在栈区 把常量区中的abc中的a的地址赋值给test4
  test4[0] = "d"; // 可改
  char* test5 = { "abc" }; // test5和test3是真的一毛一样 和直接 char* test3 = "abc" 一毛一样 abc在常量区的位置也一样
  // test5[0] = 'd'; // 报错 不可改
  cout << 0 << ':' << (test5 == test3) << endl; // 输出1
  char* test6[] = { "a", "b", "c" }; // 依次把 a b c的常量区地址 注入到test6那块栈区
  // test6[0] = "d"; // 是直接 把 "d" 在堆内存中的地址甩给test6[0]
  char test7[] = "abc"; // abc在常量区 以每次4字节4字节的方式 循环注入到 在栈区中的 test7
  char test8[] = { "abc" }; // 和上面test7几乎一毛一样 并且会判断常量区是否已经有abc了 如果有就直接复用了
  // char* test8[] = "abc"; // 报错
  char str2222[] = {'a'};
  char* str666[] = {"a", "b", "c"};
  cout << 777 << ':' << (str666) << (*str666) << endl;
  cout << 888 << ':' << (str666 + 1) << *(str666 + 1) << endl;
  cout << 999 << ':' << (str666 + 2) << *(str666 + 2) << endl;

  // cout << 1 << ':' << test1 << endl;   // abc
  // cout << 2 << ':' << test2 << endl;   // 地址
  // cout << 3 << ':' << test3 << endl;   // abc
  // cout << 4 << ':' << test4 << endl;   // 地址
  // cout << 5 << ':' << test5 << endl;   // abc
  // cout << 6 << ':' << test6 << endl;   // 地址
  // cout << 7 << ':' << test7 << endl;   // abc
  // cout << 8 << ':' << test8 << endl;   // abc
  /**
   * P.S. 数组是指一段连续的空间 但是这个连续的空间指的是等号左边的变量
   *      并不是说 char* str = { "a", "b", "c" } 这个a b c就是连续的
   *      而是 str 对应的指针地址和它后面的两个地址是连续的 第一个地址指向a 第二个地址指向b 第三个地址指向c
   * 
   * 对于 "abc" 和 { "abc" } 这俩形式 都是一样的 就是直接在内存常量区里开辟三个空间存放 可以被复用
   * 
   * 对于 { "a", "b", "c" } 这种形式 也是在内存中开辟三个空间 不过这三个可能就是被分开的了
   * 
   * 对于 { 'a', 'b', 'c' } 这种形式 直接就被转换成了 61 62 63 直接就被赋值给栈区了
   *                           "abc"    { "abc" }     { 'a', 'b', 'c' }     { "a", "b", "c" }
   * char str =            |          |             |                     |
   * char str[] =          |          |             |                     |
   * char* str =           |          |             |                     |
   * char* str[] =         |          |             |                     |
   * char (*str) =         |          |             |                     |
   * char (*str)[] =       |          |             |                     |
   */

  char str1[] = "abc";
  char str2[] = { "abc" };
  char str3[] = { 'a', 'b', 'c' };
  // char str4[] = { "a", "b", "c" }; // 报错 右侧是二维数组

  char* str5 = "abc";
  char* str6 = { "abc" };
  // char* str7 = { 'a', 'b', 'c' }; // 报错 abc三个都是直接生成的二进制 并不会现在内存中给个地址 所以无法直接付给指针
  // char* str8 = { "a", "b", "c" }; // 报错 右边是个二维数组 而str8只是一个指针变量而已

  // char* str9[] = "abc"; // 报错 右侧是一个字符串 而左边的str9是一个数组 数组中每个值都是个指针 这样报错其实是因为有歧义 因为左侧的 str9 不知道右侧想表达的是 "abc" 还是 "a" "b" "c", 对应"abc" str9会生成1位的数组 而对于 "a" "b" "c" str9会生成3位的数组
  char* str10[] = { "abc" }; // 可以 左侧str10是个数组 里面就存着一个指针
  cout << sizeof(str10) << endl; // 8
  cout << 1 << ':' << str10 << endl; // 输出地址
  // char* str11[] = { 'a', 'b' }; // 报错 右侧是直接生成二进制的字节 所以没有地址可以分配给栈区中的str11指针
  char* str12[] = { "a", "bc", "d" }; // 可以 左侧str12是个数组 里头存着三位指针
  cout << sizeof(str12) << endl; // 24

  // char (*str13)[] = "abc"; // 报错
  // char (*str14)[] = { "abc" }; // 报错
  // char (*str15)[] = { 'a', 'b', 'c' }; // 报错
  // char (*str16)[] = { "a" , "b"}; // 报错
  char str17[4] = "abc";
  char (*str18)[4] = &str17;
  char str19[4] = { "abc" };
  char (*str20)[4] = &str19;
  char str21[4] = { 'a', 'b', 'c' };
  char (*str22)[4] = &str21;
  // 对于这种 (*xxx)[] 来说 只要右侧是个正确的类型 并且是个地址就可以


  return 0;
}
