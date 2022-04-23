#include <iostream>
#define SIZE 10000
using namespace std;
class Stack {
    int top;
    public:
        int a[SIZE];
        Stack() { top = -1; }
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};
bool Stack::push(int x) {
    if (top >= (SIZE - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}
int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
bool Stack::isEmpty() {
    return (top < 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Stack stack1;
    int value1, value2, value3;
    cin >> value1 >> value2 >> value3;
    stack1.push(value1);
    stack1.push(value2);
    stack1.push(value3);

    cout << "The following value was popped from the stack: " << stack1.pop() << "\n";
    cout << "Currently available elements in stack: " << "\n";
    while(!stack1.isEmpty()) {
        cout << stack1.peek() << " ";
        stack1.pop();
    }

    return 0;
}
 