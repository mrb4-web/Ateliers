#include <iostream>
using namespace std;

template <typename T> T carre(T val) { return val * val; }

int main() {
    cout << carre(5) << endl; // 25
    cout << carre(3.5) << endl; // 12.25
    return 0;
}