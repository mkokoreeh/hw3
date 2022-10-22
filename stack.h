#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> //inherit vector to utilize vector functions, most functions are simple returns
{
public:
    Stack();
    //~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template<typename T>
Stack<T>::Stack() {
}

template<typename T>
bool Stack<T>::empty() const{
    if(std::vector<T>::size() == 0){
        return true;
    }
    return false;
}

template<typename T>
size_t Stack<T>::size() const{
    return std::vector<T>::size();
}

template<typename T>
void Stack<T>::push(const T& item){
    std::vector<T>::push_back(item);
}

template<typename T>
void Stack<T>::pop(){
    if(std::vector<T>::empty()==true){
        throw std::underflow_error("Container is Empty");
    }
    else{
        std::vector<T>::pop_back(); //pop_back since stacks are LIFO
    }
}

template<typename T>
const T& Stack<T>::top() const{
    if(std::vector<T>::empty()==true){
        throw std::underflow_error("Container is Empty");
    }
    else{
        return std::vector<T>::back(); //in stacks, the top is the last thing entered
    }
}
#endif