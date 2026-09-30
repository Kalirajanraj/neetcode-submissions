class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);

        ListNode* first = &dummy;
        ListNode* second = &dummy;

        // Move first n+1 nodes ahead.
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        // Move both pointers until first reaches the end.
        while (first) {
            first = first->next;
            second = second->next;
        }

        // second is now immediately before the node to remove.
        ListNode* toDelete = second->next;
        second->next = toDelete->next;

        delete toDelete;

        return dummy.next;
    }
};
