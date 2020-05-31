add_library( # 定义输出动态库 静态库 等目标
  say-hello # 后面其实可以加 STATIC 或者 SHARED 一个表示输出静态库 一个表示输出动态库 默认是静态库
  src/say-hello/hello.h
  src/say-hello/hello.cpp
)

# 上面添加了一个库 然后可以通过 target_include_directories 描述 say-hello 这个库的头文件应该去哪儿找
# 如果把这块儿注释了 那在别的文件中就没办法通过 #include <say-hello/hello.h> 找到这个头了
target_include_directories(
  say-hello
  PUBLIC # INTERFACE | PUBLIC | PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
