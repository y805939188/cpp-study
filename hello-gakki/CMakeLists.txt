add_executable(cpp-compiler main.cpp) # 定义一个叫 cpp-compiler 的可执行文件 main.cpp 作为入口

# target_link_libraries 是表示要把 say-hello 这个 lib 给链接到 cpp-compiler 这个可执行文件里
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
