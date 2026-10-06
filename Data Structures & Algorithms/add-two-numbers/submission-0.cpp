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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *iter1 = l1, *iter2 = l2;
        ListNode *newList = nullptr;
        ListNode *newListHead = nullptr;
        while(iter1 || iter2)
        {
            int val = ((iter2 && iter1) ? (iter2->val + iter1->val) : (iter1 ? iter1->val : iter2->val));
            val = val + carry;
            carry = val / 10;
            val = val % 10;
            ListNode* temp = new ListNode(val);
            if(newList == nullptr)
            {
                newListHead = temp;
                newList = newListHead;
            }
            else
            {
                newList->next = temp;
                newList = temp;
            }

            if(iter1)
                iter1 = iter1->next;
            if(iter2)
                iter2 = iter2->next;
        }

        if(carry > 0)
        {
            ListNode* temp = new ListNode(carry);
            newList->next = temp;
        }

        return newListHead;
    }
};
