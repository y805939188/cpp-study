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

# 定义一个宏变量叫 SAY_HELLO_VERSION
# PUBLIC 可以将这个宏变量传递给任何 link 了 say-hello 的 比如 hello-gakki 中 link 了 那它里面也可以用
# PRIVATE 的话就只能在 sat-hello 里面使用
# INTERFACE 和 PRIVATE 相反 say-hello 自己里面用不了 但是 link 了它的东西可以而用
target_compile_definitions(say-hello PUBLIC SAY_HELLO_VERSION=6)

# private指的是将属性只应用到本target
# public指的是将属性应用到本target和以后link的所有target
# interface指的是讲属性应用到以后link的所有target
