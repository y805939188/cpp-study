/**
 * #ifndef 在头文件中的作用（一个宏）
 * 在一个大的软件工程里面可能会有多个文件同时包含一个头文件
 * 当这些文件编译链接成一个可执行文件时 就会出现大量“重定义”的错误
 * 在头文件中实用#ifndef #define #endif能避免头文件的重定义
 * 方法：例如要编写头文件test.h
 * 在头文件开头写上两行：
 *  #ifndef _TEST_H // 相当于如果没包含xxx
 *  #define _TEST_H //一般是文件名的大写
 *    // ......
 *  
 *  #endif // 写在头文件结尾
 * 
 * 这样一个工程文件里同时包含两个test.h时 就不会出现重定义的错误了
 * 分析：当第一次包含test.h时 由于没有定义_TEST_H 条件为真
 * 这样就会包含（执行）#ifndef _TEST_H和
 * #endif之间的代码 当第二次包含test.h时前面一次已经定义了_TEST_H
 * 条件为假 #ifndef _TEST_H和 #endif之间的代码也就不会再次被包含
 * 这样就避免了重定义了
 * 
 * 还有 #pragma once 的方式 只支持windows
 * 这个是使用编译器来放置同一个文件呗多次包含 但是可移植性不好 但是能防止宏重复
 * 
 * 上面那种#ifndef的宏方式 无法防止宏的名字重名
 */

// 大O
// n表示数据规模
// O(f(n)) 表示运行算法所需要执行的指令数目 和 f(n) 成正比

// O(logn)
// logaN 和 logbN的关系
// logaN = logab * logbN
// 说白了 logaN 就等于 常数 * logbN
// 所以说对于对数复杂度的话 不管底是多少 都可以忽略成 logn

// 对于类似用递归去做斐波那契数列的
// 由于每次都调用两个递归
// 相当于一颗二叉树
// 它的复杂度就是 O(2^n)
