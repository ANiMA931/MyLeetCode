/**
 * @file minStack.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <stack>
#include <limits.h>
class MinStack
{
    //声明栈与辅助小栈
    std::stack<int> x_stack;
    std::stack<int> min_stack;

public:
    MinStack()
    {
        //初始化时，给小栈入栈最大int
        min_stack.push(INT_MAX);
    }

    void push(int x)
    {
        //入栈的同时，对比小栈栈顶与入栈元素
        x_stack.push(x);
        min_stack.push(std::min(min_stack.top(), x));
    }

    void pop()
    {
        //两栈同步出栈
        x_stack.pop();
        min_stack.pop();
    }

    int top()
    {
        return x_stack.top();
    }

    int min()
    {
        return min_stack.top();
    }
};

int main()
{
    int x = 5;
    int y = 4;
    int z = 6;
    int w = 3;
    MinStack *obj = new MinStack();
    obj->push(x);
    obj->push(y);
    obj->push(z);
    obj->push(w);
    std::cout << "top: " << obj->top() << std::endl;
    std::cout << "min: " << obj->min() << std::endl;
    obj->pop();
    std::cout << "top: " << obj->top() << std::endl;
    std::cout << "min: " << obj->min() << std::endl;
    obj->pop();
    std::cout << "top: " << obj->top() << std::endl;
    std::cout << "min: " << obj->min() << std::endl;
    obj->pop();
    std::cout << "top: " << obj->top() << std::endl;
    std::cout << "min: " << obj->min() << std::endl;
    obj->pop();
    return 0;
}
