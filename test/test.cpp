#include <iostream>

using namespace std;

class Class {
private:
    static int private_var;
};

int Class::private_var = 0;

int main(int argc, char* argv[]) {
    cout << "It works" << endl;
    return 0;
}