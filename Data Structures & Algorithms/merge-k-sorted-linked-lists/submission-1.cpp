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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        // Attach whichever list is remaining
        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }

    ListNode* mergeRange(vector<ListNode*>& lists, int left, int right)
    {
        if (left == right)
            return lists[left];

        int mid = left + (right - left) / 2;

        ListNode* l1 = mergeRange(lists, left, mid);
        ListNode* l2 = mergeRange(lists, mid + 1, right);

        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;

        return mergeRange(lists, 0, lists.size()-1);
    }
};
