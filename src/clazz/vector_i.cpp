#include "vector_i.h"

VectorI::VectorI() {
    elem_ = new double[DEFAULT_SZ];
    sz_ = DEFAULT_SZ;
}

VectorI::VectorI(int s) : elem_{new double[s]}, sz_{s} {
    for (int i = 0; i < sz_; ++i) {
        elem_[i] = 0;
    }
}

VectorI::VectorI(std::initializer_list<double> lst) : elem_{new double[lst.size()]}, sz_{static_cast<int>(lst.size())} {
    std::copy(lst.begin(), lst.end(), elem_);
}

/**
 * 析构函数
 */
VectorI::~VectorI() {
    delete[] elem_;
}

/**
 * 添加元素
 */
void VectorI::push(double d) {
    if (idx_ == sz_) {
        auto *p = new double[sz_ * 2];
        for (int i = 0; i < sz_; ++i) {
            p[i] = elem_[i];
        }
        delete[] elem_;
        elem_ = p;
        sz_ *= 2;
    }
    elem_[idx_] = d;
    ++idx_;
}

/**
 * 弹出元素
 */
double VectorI::pop() {
    if (idx_ == 0) {
        return 0;
    }
    --idx_;
    return elem_[idx_];
}

/**
 * 获取元素
 */
double VectorI::get(int i) {
    if (i < 0 || i >= sz_) {
        throw std::out_of_range{"Vt::get"};
    }
    return elem_[i];
}

/**
 * 元素个数
 */
int VectorI::size() const {
    return idx_;
}

/**
 * 操作符重载
 */
double &VectorI::operator[](int i) {
    return elem_[i];
}