# CMakeLists.txt
# 可以将当前目录编译成一个静态库，供上层程序使用
#cmake_minimum_required(VERSION 3.26)

aux_source_directory(. DIR_LIB_SRCS)

# 语法：add_library (libname [SHARED | STATIC | MODULE] [EXCLUDE_FROM_ALL] source1 source2 ... sourceN)
# SHARED: 动态库
# STATIC: 静态库
# MODULE: 在使用 dyld 的系统有效，如果不支持 dyld，则被当作 SHARED 对待
# EXCLUDE_FROM_ALL: 表示该库不会被默认构建，除非有其他的组件依赖或手工构建
# 如果不指定库类型，则通过全局的BUILD_SHARED_LIBS 的 FALSE 或 TRUE 来指定
# 不需要 lib 前缀，会自动添加
add_library (Contain ${DIR_LIB_SRCS})

