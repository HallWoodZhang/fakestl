// file: 1config3.cpp
//测试在 class template 中拥有 static data members.
// test __STL_STATIC_TEMPLATE_MEMBER_BUG, defined in <stl_config.h>
// ref. C++ Primer 3/e, p.839
// vc6[o] cb4[x] gcc[o]
// cb4 does not support static data member initialization.

#include <iostream>
using namespace std;

template <typename T>
class TestClass {
public:
    static int _data; 
};

//为 static data members 进行定义(配置内存),并设初值。

template <>
int TestClass<int>::_data = 1;

template <>
int TestClass<char>::_data = 2;

int main(int argc, char* argv[]) {
    cout << TestClass<int>::_data << endl;
    cout << TestClass<char>::_data << endl;

    TestClass<int> obji1, obji2;
    TestClass<char> objc1, objc2;

    cout << obji1._data << ' ' << obji2._data << endl;
    cout << objc1._data << ' ' << objc2._data << endl;

    obji1._data += 2;
    objc1._data += 2;

    cout << obji1._data << ' ' << obji2._data << endl;
    cout << objc1._data << ' ' << objc2._data << endl;
}