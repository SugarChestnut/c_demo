/*
    头文件一般定义的内容
*/ 
// #pragma once
#include <vector> // #include directive
#include <string>

namespace N // namespace declaration
{
    // 内连
    inline namespace P
    {
        //...
    }
    // 枚举
    enum class colors : short
    {
        red,
        blue,
        purple,
        azure
    };
    // 常量和常量表达式定义
    const double PI = 3.14; // const and constexpr definitions
    constexpr int MeaningOfLife{42};
    constexpr int get_meaning()
    {
        static_assert(MeaningOfLife == 42, "unexpected!"); // static_assert
        return MeaningOfLife;
    }
    // 别名
    using vstr = std::vector<int>; // type alias
    // 内
    extern double d;               // extern variable
// 宏定义
#define LOG // macro definition
// 预编译指令，条件判断=【
#ifdef LOG // conditional compilation directive
    void print_to_log();
#endif

    class my_class // regular class definition,
    {              // but no non-inline function definitions

        friend class other_class;

    public:
        void do_something();                                // definition in my_class.cpp
        inline void put_value(int i) { vals.push_back(i); } // inline OK

    private:
        vstr vals;
        int i;
    };

    struct RGB
    {
        short r{0}; // member initialization
        short g{0};
        short b{0};
    };

    template <typename T> // template definition
    class value_store
    {
    public:
        value_store<T>() = default;
        void write_value(T val)
        {
            //... function definition OK in template
        }

    private:
        std::vector<T> vals;
    };

    template <typename T> // template declaration
    class value_widget;
}