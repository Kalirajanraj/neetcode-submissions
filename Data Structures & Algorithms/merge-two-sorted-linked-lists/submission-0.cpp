/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;

        ListNode* iter = nullptr;
        ListNode* head = nullptr;
        while(list1 && list2)
        {
            ListNode* node;
            if(list1->val <= list2->val)
            {
                node = list1;
                list1 = list1->next;
            }
            else
            {
                node = list2;
                list2 = list2->next;
            }

            if(head == nullptr)
            {
                head = node;
                iter = node;
            }
            else
            {
                iter->next = node;
                iter = iter->next;
            }
        }

        if(list1)
        {
            iter->next = list1;
        }

        if(list2)
        {
            iter->next = list2;
        }
        return head;
    }
};
