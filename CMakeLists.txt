enable_testing()

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

cmake_minimum_required(VERSION 3.17) # cmake版本的最低要求

project(DingProject VERSION 1.0.0) # 这里表示项目名称以及项目版本

add_subdirectory(say-hello) # 增加一个子目录到编译系统
add_subdirectory(hello-gakki)

# set(MY_VAR "这里是一个变量")
# message(STATUS "这里是一个msg: ${MY_VAR}")

# # CMake 可以流程控制

# set(my_switch TRUE)

# if((my_switch STREQUAL TRUE) AND ("1" EQUAL "1")) # STREQUAL是等于
#   message(STATUS "可以流程控制")
# elseif(NOT FALSE)
#   message(STATUS "66666")
# else()
#   message(STATUS "hehehe")
# endif()

# set(my_value 6)
# while(my_value LESS 8)
#   message(STATUS "不知道有没有公司招Cmake工程师")
#   math(EXPR my_value "${my_value} + 1") # 这样就会打印两次
# endwhile()

# foreach(item IN ITEMS ding1 ding2 ding3)
#   message(STATUS "真NB啊我去, 不知道Cmake能不能开发服务器: ${item}")
# endforeach()

# # foreach(index RANGE 6) # index 从 0 开始
# # foreach(index RANGE 3 6) # index 从 3 开始一直到 6
# foreach(index RANGE 3 6 2) # 第三个参数是 step  真特么神了我去
#   message(STATUS "${index}") 
# endforeach()



# set_property(GLOBAL PROPERTY DING 1 2 3) # 设置为一个列表
# # set(my_list 1 2 3)
# # set_property(GLOBAL PROPERTY DING "${my_list}") # 也可以这么玩

# # get_cmake_property(ding_value DING) # 第一种取值方式

# get_property(ding_value GLOBAL PROPERTY DING) # 第二种取值方式
# message(STATUS "还特么能设置变量 一会儿是不是能写函数了: ${ding_value}") # 打印这个 1;2;3

# message(STATUS "${PROJECT_SOURCE_DIR}") # PROJECT_SOURCE_DIR 不管在那个文件下都是打印的根目录



# set(target DIRECTORY "${PROJECT_SOURCE_DIR}") # 创建一个 target 变量 是一个文件地址
# set_property(${target} PROPERTY DING2 1 2 3)
# get_property(ding2_value ${target} PROPERTY DING2)
# message(STATUS "值是 ${ding2_value}")

# function(func_name arg1 arg2)
#   message(STATUS "这里的参数在调用函数时候必须传两个不能少 可以多 但是多的就没了: ${arg1} ${arg2}")
# endfunction()

# func_name(1 2)

# function(func_name_2)
#   foreach(arg IN LISTS ARGN)
#     message(STATUS "可以通过这种方式获取参数们: ${arg}")
#   endforeach()  
# endfunction()

# func_name_2(1 2 3)

# message(STATUS "----------------------------------------")

# function(func_name_3 a b c)
#   foreach(arg IN LISTS ARGV) # 这种 ARGV 会打印 1 2 3 4 5 6
#     message(STATUS "可以通过这种方式获取参数们: ${arg}")
#   endforeach()
#   message(STATUS "----------------------------------------")
#   foreach(arg IN LISTS ARGN) # 这种 ARGN 只打印 4 5 6
#     message(STATUS "可以通过这种方式获取参数们: ${arg}")
#   endforeach()  

#   # 另外函数内部可以访问到外部的变量
#   set(MY_GLOBAL_VAR 88 PARENT_SCOPE)
# endfunction()
# set(MY_GLOBAL_VAR 66)
# func_name_3(1 2 3 4 5 6)
# message(STATUS "${MY_GLOBAL_VAR}") # 这里会打印 88 因为在函数中给他重新赋值了

# function(func_name4 var)
#   message(STATUS "这里的参数在函数调用时是通过变量传过来的 所以得这么写: ${${var}}")
#   set("${var}" 88 PARENT_SCOPE) # 可以给外部变量重新赋值
# endfunction()
# set(value 66)
# func_name4(value)
