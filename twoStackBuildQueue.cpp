#include <stack>

class CQueue {
private:
    //声明入栈与出栈
    std::stack<int> inStack, outStack;

    //定义入栈倒出栈的方法
    void in2out() {
        //当入栈没有空的时候
        while (!inStack.empty()) {
            //把入栈的栈顶元素取出，放到出栈中
            outStack.push(inStack.top());
            //弃掉入栈的此栈顶元素
            inStack.pop();
        }
    }

public:
    CQueue() {}

    //两栈实现的队尾插入就直接把元素放到入栈中即可
    void appendTail(int value) {
        inStack.push(value);
    }

    //删除队头元素
    int deleteHead() {
        //如果出栈是空的
        if (outStack.empty()) {
            //且入栈是空的，说明没有元素，返回-1
            if (inStack.empty()) {
                return -1;
            }
            //入栈倒出栈
            in2out();
        }
        //获取出栈的栈顶元素并返回
        int value = outStack.top();
        //出栈
        outStack.pop();
        return value;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/solution/mian-shi-ti-09-yong-liang-ge-zhan-shi-xian-dui-l-3/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。