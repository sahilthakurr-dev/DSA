#include <iostream>
using namespace std;

//inline function body should be less than 3 
inline int square(int x) {
    return x * x;
}

int main() {
    cout << square(5);  // Compiler replaces this with (5 * 5)
    return 0;
}
