/**
 * @file reverseLinkList.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-30
 *
 * @copyright Copyright (c) 2022
 *
 */
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
    ListNode *reverseList(ListNode *head)
    {
        //声明一个指向前一个节点的指针和指向当前节点的指针，初始化为链表头
        ListNode *prev = nullptr;
        ListNode *curr = head;
        //当前节点指针指向的不为null时
        while (curr)
        {
            //声明一个临时指针指向当前节点的下一个节点指针指向的位置
            ListNode *next = curr->next;
            //让当前节点的next指针指向前一个节点
            curr->next = prev;
            //让前一个节点的指针指向当前节点指针指向的位置
            prev = curr;
            //让当前节点指针指向next指针指向的位置
            curr = next;
        }
        return prev;
    }
};

int main()
{
    ListNode *n1 = new ListNode(4);
    ListNode *n2 = new ListNode(3);
    n1->next = n2;
    Solution *s;
    ListNode *a = s->reverseList(n1);
    while(a)
    {
        std::cout<<a->val<< ' ';
        a = a->next;
    }
    std::cout << std::endl;
    delete n2;
    delete n1;
    return 0;
}
// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/solution/fan-zhuan-lian-biao-by-leetcode-solution-jvs5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。