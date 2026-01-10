#include <iostream> // For std::cout

#include "generic_stack.hpp" // for menny::GenericStack
#include "test_utils.hpp" // for menny::test_utils::PrintTestResult

int main()
{
    menny::GenericStack<int> stack;

    // Test 1: Stack should be empty initially
    PRINT_TEST_RESULT(1, "Stack is initially empty", true, stack.empty());

    // Test 2: Push an element and check if stack is not empty
    stack.push(42);
    PRINT_TEST_RESULT(2, "Stack is not empty after push", false, stack.empty());
     
    // Test 3: Check top element
    PRINT_TEST_RESULT(3, "Top element is 42", 42, stack.top());

    // Test 4: Pop the element and check if it is correct
    int popped_value = stack.pop();
    PRINT_TEST_RESULT(4, "Popped element is 42", 42, popped_value);

    // Test 5: Stack should be empty after pop
    PRINT_TEST_RESULT(5, "Stack is empty after pop", true, stack.empty());

    // Test 6: Attempt to pop from empty stack should throw exception
    bool exception_thrown = false;
    try
    {
        stack.pop();
    }
    catch (const std::out_of_range&)
    {
        exception_thrown = true;
    }
    PRINT_TEST_RESULT(6, "Exception thrown on pop from empty stack", true, exception_thrown);

    return 0;
}   

using namespace menny;

