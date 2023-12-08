#include <iostream>
// using namespace std;
#include <cmath>

// constexpr int calc(int);

constexpr int calc(int a)
{
    return a + 1;
}

/**
 * 指针
 * 指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址
 */
void p()
{
    /*
        p1是一个指向int的指针
        p2是一个int
        p3是一个指向int的指针
        p4是一个int
    */
    int *p1 = nullptr, p2 = 0;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    // p5是一个int
    int p5 = 8;
    // p6是一个指向int的指针
    int *p6 = &p5;
    // p7是一个指向指针的引用
    int *&p7 = p6;
    std::cout << p7 << std::endl;
    std::cout << *p7 << std::endl;
}

/**
 * 数组
 */
void container()
{
    // 自动类型推导
    auto i = 123;
    // 常量表达式，编译时计算
    constexpr auto x = calc(88);
    std::cout << x << std::endl;

    /*
        T a[n]  是一个含有n个T类型的数组
        T* p    是一个指向T类型对象的指针
        T& r    是一个引用，绑定到T类型的对象
        T f(A)  是一个以类型A为参数并返回类型T的函数
    */
    int array[] = {1, 2, 3, 4, 5};
    int *p = &array[1];
    int *q = &array[1];
    // ++ 优先级高于 *
    *p += 1;
    std::cout << p << std::endl;
    std::cout << (p == q) << std::endl;
    std::cout << array[1] << std::endl;

    // 一元后置操作符 & 表示指向前者的引用
    for (auto &e : array)
    {
        std::cout << e;
    }

    std::cout << std::endl;

    for (auto e : array)
    {
        std::cout << e;
    }
    std::cout << std::endl;
}