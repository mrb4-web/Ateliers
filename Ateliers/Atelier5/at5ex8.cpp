#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
    int* data;
    int top, capacity;
public:
    Stack(int cap = 20) : capacity(cap), top(-1), data(new int[cap]) {}
    Stack(const Stack& s) : capacity(s.capacity), top(s.top), data(new int[s.capacity]) {
        for (int i = 0; i <= top; ++i) data[i] = s.data[i];
    }
    ~Stack() { delete[] data; }
    Stack& operator=(const Stack&) = delete; // Interdit
    Stack& operator<<(int n) {
        if (top == capacity - 1) throw runtime_error("Pile pleine");
        data[++top] = n;
        return *this;
    }
    Stack& operator>>(int& n) {
        if (top == -1) throw runtime_error("Pile vide");
        n = data[top--];
        return *this;
    }
    int operator++() { return top == capacity - 1 ? 1 : 0; }
    int operator--() { return top == -1 ? 1 : 0; }
};

int main() {
    Stack s;
    int n;
    s << 1 << 2 << 3;
    s >> n; cout << n << endl; // 3
    return 0;
}