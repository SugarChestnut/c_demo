#include "vector_i.h"

template<typename T>
VectorI<T>::VectorI() {
    elem_ = new T[DEFAULT_SZ];
    sz_ = DEFAULT_SZ;
}

template<typename T>
VectorI<T>::VectorI(int s) : elem_{new T[s]}, sz_{s} {
    for (int i = 0; i < sz_; ++i) {
        elem_[i] = 0;
    }
}

template<typename T>
VectorI<T>::VectorI(std::initializer_list<T> lst) : elem_{new T[lst.size()]}, sz_{static_cast<int>(lst.size())} {
    std::copy(lst.begin(), lst.end(), elem_);
}
// 移动构造函数
template<typename T>
VectorI<T>::VectorI(VectorI<T> &&v) noexcept : elem_{v.elem_}, sz_{v.sz_} {
    // 说明原数组被新的对象接管了，不需要释放
    std::cout << "移动构造函数" << std::endl;
    v.elem_ = nullptr;
    v.sz_ = 0;
}
// 拷贝构造函数
template<typename T>
VectorI<T>::VectorI(const VectorI &v) : elem_{new double[v.sz_]}, sz_{v.sz_} {
    std::cout << "拷贝构造函数" << std::endl;
    std::copy(v.elem_, v.elem_ + v.sz_, elem_);
}
// 移动赋值运算符
template<typename T>
VectorI<T> &VectorI<T>::operator=(VectorI<T> &&v) noexcept {
    std::cout << "移动赋值运算符" << std::endl;
    elem_ = v.elem_;
    sz_ = v.sz_;
    v.elem_ = nullptr;
    v.sz_ = 0;
    return *this;
}
// 拷贝赋值运算符
template<typename T>
VectorI<T> &VectorI<T>::operator=(const VectorI<T> &v) {
    std::cout << "拷贝赋值运算符" << std::endl;
    if (this == &v) {
        return *this;
    }
    auto *p = new double[v.sz_];
    std::copy(v.elem_, v.elem_ + v.sz_, p);
    delete[] elem_;
    elem_ = p;
    sz_ = v.sz_;
    return *this;
}

/**
 * 析构函数
 */
template<typename T>
VectorI<T>::~VectorI() {
    delete[] elem_;
}

/**
 * 添加元素
 */
template<typename T>
void VectorI<T>::push(T d) {
    if (idx_ == sz_) {
        auto *p = new T[sz_ * 2];
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
template<typename T>
T VectorI<T>::pop() {
    if (idx_ == 0) {
        return 0;
    }
    --idx_;
    return elem_[idx_];
}

/**
 * 获取元素
 */
template<typename T>
T VectorI<T>::get(int i) {
    if (i < 0 || i >= sz_) {
        throw std::out_of_range{"Vt::get"};
    }
    return elem_[i];
}

/**
 * 元素个数
 */
template<typename T>
int VectorI<T>::size() const {
    return sz_;
}

/**
 * 操作符重载
 */
template<typename T>
T &VectorI<T>::operator[](int i) {
    if (i < 0 || i >= sz_) {
        throw std::out_of_range{"Vt::operator[]"};
    }
    return elem_[i];
}