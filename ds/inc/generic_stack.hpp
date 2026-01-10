# ifndef __MENNY_GENERIC_STACK_HPP__
# define __MENNY_GENERIC_STACK_HPP__

#include <vector>
#include <stdexcept>

namespace menny
{

template<typename T>
class GenericStack
{
public:
    void push(const T& item);
    T pop();
    T top() const;
    bool empty() const;

private:
    std::vector<T> stack;    
}; // class GenericStack

template<typename T>
void GenericStack<T>::push(const T& item)
{
    stack.push_back(item);
}

template<typename T>
T GenericStack<T>::pop()
{
    if (stack.empty())
    {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }

    T item = stack.back();
    stack.pop_back();

    return item;
}        

template<typename T>
T GenericStack<T>::top() const
{
    if (stack.empty())
    {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    
    return stack.back();
}

template<typename T>
bool GenericStack<T>::empty() const
{
    return stack.empty();
}   

} // namespace menny

# endif // __MENNY_GENERIC_STACK_HPP__