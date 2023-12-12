#include <iostream>
// 异常标准库
#include "./container/container_i.cpp"
#include <stdexcept>

void use(ContainerI &c) {
    const int sz = c.size();
    for (int i = 0; i < sz; ++i) {
        std::cout << c[i];
    }
    std::cout << std::endl;
}

VectorI f() {
    VectorI v(10);// 普通构造函数
    v[0] = 1;
    VectorI v1 = std::move(v);                     // 移动构造函数，v1 拥有 v 的资源，v 清空
    VectorI v2 = v1;                               // 拷贝构造函数，v2 拥有 v1 的资源，v1 不变
    std::cout << "v1[0]-b: " << v1[0] << std::endl;// 1
    std::cout << "v2[0]-b: " << v2[0] << std::endl;
    v1[0] = 2;
    std::cout << "v1[0]-a: " << v1[0] << std::endl;
    std::cout << "v2[0]-a: " << v2[0] << std::endl;

    VectorI x(10);
    VectorI y(20);
    VectorI z(30);
    z = x;           // 拷贝赋值运算符
    y = std::move(x);// 移动赋值运算符，y 拥有 x 的资源，x 清空，x 随着函数结束销毁
    std::cout << "return" << std::endl;
    std::cout << &x << std::endl;
    std::cout << &y << std::endl;
    std::cout << &z << std::endl;
    return z;
}

/*
    交换两个指针的值，不会改变原来的值
        int a = 1, b = 2;
        s(&a, &b);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        s1(a, b);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
*/
void s(int *a, int *b) {
    int *c = a;
    a = b;
    b = c;
}
/*
    交换两个引用的值，会改变原来的值
*/
void s1(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

/*
    noexcept：表示函数不会抛出异常，如果抛出异常，程序会调用terminate()函数终止程序
*/
int main() noexcept {
    VectorContainer vc(10);
    use(vc);

    VectorI v = f();// v z 拥有相同的地址
    std::cout << &v << std::endl;
    std::cout << v.size() << std::endl;
}