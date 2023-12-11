#ifndef VECTOR_I_H
#define VECTOR_I_H

#include <iostream>

class VectorI {
private:
    double *elem_;
    int sz_;
    int idx_ = 0;

public:
    const int DEFAULT_SZ = 16;

    // 构造函数
    VectorI();

    /*
      类构造函数默认情况下是隐式调用的。
      在C++中, 如果的构造函数只有一个参数时,
      那么在编译的时候就会有一个缺省的转换操作:将该构造函数对应数据类型的数据转换为该类对象
      例外：除了第一个参以外的其他参数都有默认值的情况下，该构造函数可以隐式调用
      VectorI v = 10; 会隐式调用 VectorI(int s) 构造函数

      explicit（显式）关键字表示该构造函数不能隐式调用
      例如：VectorI v = 10; 会报错

      implicit（隐式）关键字表示该构造函数可以隐式调用
    */
    explicit VectorI(int sz);

    VectorI(std::initializer_list<double> lst);

    // 禁用拷贝构造函数
    VectorI(const VectorI &v);

    // 移动构造函数
    VectorI(VectorI &&v) noexcept;

    // 禁用拷贝赋值运算符
    VectorI& operator=(const VectorI &v);

    // 移动赋值运算符
    VectorI& operator=(VectorI&& v) noexcept;

    // 析构函数
    ~VectorI();

    double &operator[](int i);

    [[nodiscard]] int size() const;

    void push(double d);

    double pop();

    double get(int i);
};

#endif