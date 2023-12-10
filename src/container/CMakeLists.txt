# CMakeLists.txt
# 可以将当前目录编译成一个静态库，供上层程序使用
#cmake_minimum_required(VERSION 3.26)

set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/out")

aux_source_directory(. DIR_LIB_SRCS)

# 语法：add_library (libname [SHARED | STATIC | MODULE] [EXCLUDE_FROM_ALL] source1 source2 ... sourceN)
# 说明：用于生成库文件，可以是静态库，也可以是动态库
# 参数说明：
#     参数1（libname）: 指定生成库文件的名称，也就是我们使用target_link_libraries命令时需要指定的名称
#     参数2：SHARED（动态库），STATIC（静态库），MODULE（在使用dyld的系统有效，如果不支持则被当作SHARED对待）
#           如果不指定库类型，则通过全局的BUILD_SHARED_LIBS 的 FALSE 或 TRUE 来指定
#     参数3（EXCLUDE_FROM_ALL）: 表示该库不会被默认构建，除非有其他的组件依赖或手工构建
#     参数4：指定生成库文件的源码文件
# 注意：不需要 lib 前缀，会自动添加
add_library (container SHARED ${DIR_LIB_SRCS})
# add_library(container STATIC ${DIR_LIB_SRCS})

# 语法：target_include_directories(target [SYSTEM] [BEFORE] <INTERFACE|PUBLIC|PRIVATE> [items1...] [items2...] ...)
# 说明：target_include_directories 指定了头文件的搜索路径，可以是相对路径也可以是绝对路径
# target_include_directories(container PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)