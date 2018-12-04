#include "simpleAllocator0.h"

#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int ia[5] = {1, 2, 3, 4, 5};
    unsigned int i;
    vector<int, SA0::allocator<int> > iv(ia, ia+5);
    for(int i = 0; i < 5; ++i) {
        cout << iv[i] << ' ';
    }

    cout << endl;
}