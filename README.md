# 学习笔记

用vscode开发c++，你需要先学gcc, makefile, cmake, c++的编译过程，如何链接库，如何引入头文件，以及如何配置vscode中的launch.json, task.json和c_cpp_properties.json

## autoconf

根据平台的不同，生成 configure 检查脚本

使用 autoscan 根据源代码，自动生成 configure.ac

使用 autoconf 根据 configure.ac 生成 configure 脚本

使用 autoheader

## configure

脚本文件，检查配置，并设置参数

使用 automake 根据 Makefile.am 生成 Makefile.in

configure 根据 Makefile.in 生成 Makefile 文件

## Makefile

Makefile 解决的是编译问题

凡是要一次次重新执行的命令，都应该写成一个脚本

Makefile 不是必须的，但是能减少你很多麻烦

make 是一个工具，是一个解释 Makefile 中指令的工具

## Cmake
