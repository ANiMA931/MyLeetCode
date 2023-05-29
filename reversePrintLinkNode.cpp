/**
 * @file reversePrintLinkNode.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stack>
#include <vector>
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    std::vector<int> reversePrint(ListNode *head)
    {
        //先声明一个栈，再声明一个向量
        std::stack<int> stack;
        std::vector<int> ans;
        //遍历链表，若当前节点不为null,则将节点val入栈
        while (head != NULL)
        {
            stack.push(head->val);
            head = head->next;
        }
        //当栈不为空时，取栈顶元素放入向量，并出栈
        while (!stack.empty())
        {
            ans.push_back(stack.top());
            stack.pop();
        }
        return ans;
    }
};
int main()
{
    ListNode *n1 = new ListNode(4);
    ListNode *n2 = new ListNode(3);
    n1->next = n2;
    Solution *s;
    std::vector<int> a = s->reversePrint(n1);
    for (std::vector<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        std::cout << *i << ' ';
    }
    std::cout<<std::endl;
    delete n1;
    delete n2;
    return 0;
}