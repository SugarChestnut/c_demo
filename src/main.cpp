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
    VectorI v(10);
    v[0] = 1;
    VectorI v1 = std::move(v);                     // 移动构造函数，v1 拥有 v 的资源，v 为空
    VectorI v2 = v1;                               // 拷贝构造函数
    std::cout << "v1[0]-b: " << v1[0] << std::endl;// 1
    std::cout << "v2[0]-b: " << v2[0] << std::endl;
    v1[0] = 2;
    std::cout << "v1[0]-a: " << v1[0] << std::endl;
    std::cout << "v2[0]-a: " << v2[0] << std::endl;

    VectorI x(10);
    VectorI y(20);
    VectorI z(30);
    z = x;           // 拷贝赋值运算符
    y = std::move(x);// 移动赋值运算符
    return z;
}

/*
    noexcept：表示函数不会抛出异常，如果抛出异常，程序会调用terminate()函数终止程序
*/
int main() noexcept {
    //    VectorContainer vc(10);
    //    use(vc);

    VectorI v = f();
    std::cout << v[0] << std::endl;
}