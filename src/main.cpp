#include <iostream>
// 异常标准库
#include <stdexcept>
#include "./container/container_i.cpp"

void use(ContainerI &c) {
    const int sz = c.size();
    for (int i = 0; i < sz; ++i) {
        std::cout << c[i] << std::endl;
    }
}

/*
    noexcept：表示函数不会抛出异常，如果抛出异常，程序会调用terminate()函数终止程序
*/
int main() noexcept {
    using namespace std;
    cout << "Hello, World!--" << endl;
    try {
        /* code */
        throw out_of_range{"aa"};
    }
    catch (const exception &e) {
        cerr << e.what() << '\n';
    }

    VectorContainer vc(10);
    use(vc);
}