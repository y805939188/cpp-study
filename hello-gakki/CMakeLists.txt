add_executable(cpp-compiler main.cpp) # 定义一个叫 cpp-compiler 的可执行文件 main.cpp 作为入口

# target_link_libraries 是表示要把 say-hello 这个 lib 给链接到 cpp-compiler 这个可执行文件里
# PUBLIC 如果 cpp-compiler 的头文件里头包含了 say-hello 的头文件 同时源文件包含了 cpp-compiler 自己的头文件的话就用 PUBLIC
# PRIVATE 如果 cpp-compiler 只有源文件里包含了依赖的头文件 那就用 PRIVATE
# INTERFACE 如果 cpp-compiler 的头文件包含 say-hello 但源文件未包含 那就用INTERFACE
target_link_libraries(cpp-compiler PRIVATE say-hello)

# 也可以设置链接非标准路径中别人编译好的库
# target_link_libraries(test_elf 
#   PRIVATE 
#   $ENV{HOME}/lib/libtest.a
# )


# #定义一个动态库archive 输出目标，文件有三个源文件
# add_library(archive SHARED archive.cpp zip.cpp lzma.cpp)

# #定义一个静态库archive 输出目标，也可以不指定STATIC 因为add_library默认输出目标是#静态库
# add_library(archive STATIC archive.cpp zip.cpp lzma.cpp)


# 还可以写测试 需要在根目录下加上 enable_testing()
# 并且如果设置了静态库或者可执行文件的输出路径的话 可能会报一个 Not Run 的错
add_executable(test-compiler main-test.cpp)
add_test(my-test test-compiler)
# set_property(TEST my-test PROPERTY PASS_REGULAR_EXPRESSION "d") # 判断输出的是不是ding
set_tests_properties(my-test PROPERTIES PASS_REGULAR_EXPRESSION ding)
