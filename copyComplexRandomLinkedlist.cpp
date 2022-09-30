/**
 * @file copyComplexRandomLinkedlist.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            // 创建一个新的链表节点，值与当前遍历节点相同
            Node *nodeNew = new Node(node->val);
            // 让新节点的后继节点指针指向与当前遍历节点同一个后记节点指针指向的内容
            nodeNew->next = node->next;
            // 让当前遍历节点的后继节点指针指向新节点
            node->next = nodeNew;
            // 这个时候需要取两次next才能访问到原先链表的下一个节点
        }

        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            // 获取新链表的节点
            Node *nodeNew = node->next;
            // 让两个节点的随机指针保持一致
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        // 循环外保存一个节点指针
        Node *headNew = head->next;
        for (Node *node = head; node != nullptr; node = node->next)
        {
            Node *nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};

int main()
{
    return 0;
}

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/solution/fu-za-lian-biao-de-fu-zhi-by-leetcode-so-9ik5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。