#include "./vector_i.h"

/*
    抽象类没有构造函数，因为不需要初始化数据
    virtual（虚函数）的意思是：可能会被子类重写的函数
    含有纯虚函数的类是抽象类，抽象类不能被实例化，只能被继承
*/
class ContainerI {
public:
    // 纯虚函数，=0 表示该函数是纯虚函数，没有默认实现，意味着派生类必须定义该函数
    virtual double &operator[](int) = 0;

    //
    [[nodiscard]] virtual int size() const = 0;

    /*
     * 虚析构函数
     * =default 表示显式要求编译器生成默认的析构函数（不指定也会生成）
     */
    virtual ~ContainerI() = default;
};

/*
    派生类
*/
class VectorContainer : public ContainerI {
private:
    VectorI<double> v;

public:
    explicit VectorContainer(int s) : v(s) {}

    ~VectorContainer() override = default;

    /*
      override（标识，也可以不写）关键字表示该函数是重写基类的虚函数
      有利于编译器检查是否真的重写了基类的虚函数
    */
    double &operator[](int i) override { return v[i]; }

    [[nodiscard]] int size() const override {
        return v.size();
    }
};
