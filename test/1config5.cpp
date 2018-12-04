// file: 1config5.cpp
//测试 class template partial specialization —在 class template 的
// 一般化设计之外,特别针对某些 template 参数做特殊设计。
// test __STL_CLASS_PARTIAL_SPECIALIZATION in <stl_config.h>
// ref. C++ Primer 3/e, p.860
// vc6[x] cb4[o] gcc[o]


#include <iostream>
using namespace std;

//一般化设计
template <class I, class O>
struct TestClass {
    TestClass() { cout << "I, O" << endl; }
};

//特殊化设计
template <class T>
struct TestClass<T*, T*> {
    TestClass() { cout << "T*, T*" << endl; }
};

//特殊化设计
template <class T>
struct TestClass<const T*, T*> {
    TestClass() { cout << "const T*, T*" << endl; }
};

int main(int argc, char* argv[]) {
    TestClass<int, char> obj1;
    TestClass<int*, int*> obj2;
    TestClass<const int*, int*> obj3;
}
