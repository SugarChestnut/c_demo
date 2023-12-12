#include "./container/vector_i.h"

/*
    非模版函数 > 具体化模版 > 常规模版
*/

// 模版函数
template<typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// 
template<typename T>
void swap(VectorI<T> &a, VectorI<T> &b) {
    int l = a.size() > b.size() ? b.size() : a.size();
    for (int i = 0; i < l; ++i) {
        swap(a[i], b[i]);
    }
}

// 显示具体化模版函数
template<>
void swap<VectorI<double>>(VectorI<double> &a, VectorI<double> &b) {
    int l = a.size() > b.size() ? b.size() : a.size();
    for (int i = 0; i < l; ++i) {
        swap(a[i], b[i]);
    }
}

// 非模版函数
void swap(VectorI<double> &a, VectorI<double> &b) {
    int l = a.size() > b.size() ? b.size() : a.size();
    for (int i = 0; i < l; ++i) {
        swap(a[i], b[i]);
    }
}