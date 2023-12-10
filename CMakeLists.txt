# 使用 ${} 语法来引用变量
# 使用 set() 函数来设置变量
# 命令（https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html）
# 常用变量（https://cmake.org/cmake/help/latest/manual/cmake-variables.7.html）
#   PROJECT_NAME                项目名称
#   PROJECT_BINARY_DIR          项目的二进制文件目录，即编译后的可执行文件和库文件的输出目录
#   PROJECT_SOURCE_DIR          项目的源文件目录，即包含CMakeLists.txt文件的目录
#   CMAKE_BINARY_DIR            当前CMake运行的二进制文件目录，通常和PROJECT_BINARY_DIR是同一个目录
#   CMAKE_SOURCE_DIR            当前CMake运行的源文件目录，通常和PROJECT_SOURCE_DIR是同一个目录
#   CMAKE_C_STANDARD            指定C语言的标准版本
#   CMAKE_CXX_STANDARD          指定C++语言的标准版本
#   CMAKE_CXX_FLAGS             指定编译C++代码时使用的编译选项
#   CMAKE_C_FLAGS               指定编译C代码时使用的编译选项
#   CMAKE_EXE_LINKER_FLAGS      指定链接可执行文件时使用的链接选项
#   CMAKE_SYSTEM_NAME           指定当前操作系统名称（如Windows、Linux等）
#   CMAKE_SYSTEM_PROCESSOR      指定当前处理器的类型（如x86、x86_64等）
#   CMAKE_SYSTEM_VERSION        系统版本
#   CMAKE_INSTALL_PREFIX        指定安装路径
#   CMAKE_MODULE_PATH           指定模块路径
#   CMAKE_BUILD_TYPE            指定编译类型 Debug/Release
#   LIBRARY_OUTPUT_PATH         指定库输出路径
#   EXECUTABLE_OUTPUT_PATH      指定可执行文件输出路径

# 声明要求的 cmake 最低版本或者范围
cmake_minimum_required(VERSION 3.26...3.28)

# 语法：project(<name> [VERSION <version>] [LANGUAGES <language-name>])
# 说明：指定项目名称，版本，语言
# 项目名称，保存到 PROJECT_NAME 变量中
# 隐含的定义了 PROJECT_SOURCE_DIR（包含 CMakeLists 文件的目录） 和 PROJECT_BINARY_DIR（项目二进制文件目录） 变量
project(rtt_base VERSION 1.0.0 LANGUAGES CXX)

message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}")

# 判断当前项目是作为子项目还是独立项目
set(MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
endif ()

# 编译标准
set(CMAKE_CXX_STANDARD 20)
# 有些情况下可能不是静态链接，导致运行时找不到库文件，可以使用下面的语句强制静态链接
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/out")

# 语法：find_package(<name> [major.minor] [QUIET] [NO_MODULE] [[REQUIRED|COMPONENTS] [components...]] [OPTIONAL_COMPONENTS components...] [NO_POLICY_SCOPE])
# 说明：在本地搜索第三方库，如果找到，就定义一系列变量，REQUIRED 表示必须找到，否则报错
# 通过 find_package() 找到的包，会定义 <name>_FOUND 变量，例如 Boost_FOUND
# 通过 find_package() 找到的包，会定义 <name>_INCLUDE_DIRS 变量，例如 Boost_INCLUDE_DIRS
# 通过 find_package() 找到的包，会定义 <name>_LIBRARIES 变量，例如 Boost_LIBRARIES
# 通过 find_package() 找到的包，会定义 <name>_LIBRARY_DIRS 变量，例如 Boost_LIBRARY_DIRS
# 通过 find_package() 找到的包，会定义 <name>_DEFINITIONS 变量，例如 Boost_DEFINITIONS
# 通过 find_package() 找到的包，会定义 <name>_VERSION 变量，例如 Boost_VERSION
# 通过 find_package() 找到的包，会定义 <name>_INCLUDE_DIR 变量，例如 Boost_INCLUDE_DIR
# 通过 find_package() 找到的包，会定义 <name>_LIBRARY_DIR 变量，例如 Boost_LIBRARY_DIR
# 通过 find_package() 找到的包，会定义 <name>_LIBRARY 变量，例如 Boost_LIBRARY
find_package(Boost COMPONENTS filesystem system)
if (Boost_FOUND)
    message(STATUS "Boost found")
else ()
    message(STATUS "Boost not found")
endif ()

# 在指定路径中搜索文件名,指定路径指的是环境变量 CMAKE_INCLUDE_PATH 中包含的所有路径。
#find_path()

# 语法：find_library(<VAR> name1 [path1 path2 ...])
# 说明：在指定路径中搜索库文件，指定路径指的是环境变量 CMAKE_LIBRARY_PATH 中包含的所有路径。
#find_package()

# 输出编译信息
set(CMAKE_VERBOSE_MAKEFILE ON)

# 语法：include_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])
# 说明：增加头文件搜索路径
include_directories()
# 语法：target_include_directories(<target> [SYSTEM] [BEFORE] <INTERFACE|PUBLIC|PRIVATE> [items1...] [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
# 说明：通过设置导出权限，将指定目录添加到指定目标的头文件搜索路径中
#target_include_directories()
# 与 include_directories 的作用类似，增加库文件搜索路径
link_directories()
#target_link_directories()

# 语法：add_definitions(<list of definitions>)
# 说明：向工程添加预定义的宏，相当于在源文件中添加 #define 宏名
add_definitions()

# 语法：aux_source_directory(<dir> <variable>)
# 说明：在指定目录下查找所有源文件，将结果存进指定变量名，不包含子目录
# 等效 set(DIR_SRCS ./src/main.cpp ./xxx.cpp)
# 等效 file(GLOB DIR_SRCS ./src/*.cpp) --- file 还有许多其他功能
aux_source_directory(./src DIR_SRCS)

# 语法：add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
# 说明：用于添加子项目目录，如果有该命令，会先进入该目录执行 CMakeLists.txt 文件
add_subdirectory(./src/container)

# 语法：add_executable(<name> [WIN32] [MACOSX_BUNDLE] [EXCLUDE_FROM_ALL] source1 source2 ...)
# 说明：将指定的源文件生成链接文件
# add_executable(rtt_base ${DIR_SRCS})
# 第一个参数可以作为target_xxx命令的接收对象，例如 target_link_libraries()
add_executable(${PROJECT_NAME} ${DIR_SRCS})

# 语法：target_link_libraries(<target> [item1] [item2] [...])
# 说明：将目标文件链接到库文件或可执行文件
target_link_libraries(${PROJECT_NAME} container)
