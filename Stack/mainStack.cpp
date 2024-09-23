#include "ArrayStack.h"
#include "LinkedStack.h"
#include <iostream>
using std::endl;
using  std::cout;
void testStackOperations() {
    ArrayStack<int> stack;

    // Test case 1: Test stack operations
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "stack: " << stack.toString() << endl;
    std::cout << "Top element after 3 pushes: " << stack.top() << std::endl; // Expected: 30
    stack.pop();
    std::cout << "Top element after 1 pop: " << stack.top() << std::endl; // Expected: 20
    stack.pop();
    std::cout << "Top element after 2 pops: " << stack.top() << std::endl; // Expected: 10
    stack.pop();
    std::cout << "Stack empty after 3 pops: " << (stack.empty() ? "true" : "false") << std::endl; // Expected: true

    // Test case 2: Test stack storage
    for (int i = 0; i < 100; ++i) {
        stack.push(i);
    }
    std::cout << "Stack size after pushing 100 elements: " << stack.size() << std::endl; // Expected: 100
    std::cout << "Top element after pushing 100 elements: " << stack.top() << std::endl; // Expected: 99

    stack.clear();
    std::cout << "Stack empty after clear: " << (stack.empty() ? "true" : "false") << std::endl; // Expected: true
}
void testLinkedStackOperations() {
    LinkedStack<int> lstack;

    // Test case 1: Test stack operations
    lstack.push(10);
    lstack.push(20);
    lstack.push(30);

    cout << "lstack: " << lstack.toString() << endl;
    std::cout << "Top element after 3 pushes: " << lstack.top() << std::endl; // Expected: 30
    lstack.pop();
    std::cout << "Top element after 1 pop: " << lstack.top() << std::endl; // Expected: 20
    lstack.pop();
    std::cout << "Top element after 2 pops: " << lstack.top() << std::endl; // Expected: 10
    lstack.pop();
    std::cout << "Stack empty after 3 pops: " << (lstack.empty() ? "true" : "false") << std::endl; // Expected: true

    // Test case 2: Test stack storage
    for (int i = 0; i < 100; ++i) {
        lstack.push(i);
    }
    std::cout << "Stack size after pushing 100 elements: " << lstack.size() << std::endl; // Expected: 100
    std::cout << "Top element after pushing 100 elements: " << lstack.top() << std::endl; // Expected: 99

    lstack.clear();
    std::cout << "Stack empty after clear: " << (lstack.empty() ? "true" : "false") << std::endl; // Expected: true
}





int main() {
    testStackOperations();
    testLinkedStackOperations();
    return 0;
}
