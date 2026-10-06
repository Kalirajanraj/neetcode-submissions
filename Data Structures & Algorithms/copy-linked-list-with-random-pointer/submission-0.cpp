/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> m;

        // Pass 1: Create all copied nodes
        Node* curr = head;

        while (curr) {
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Pass 2: Connect next and random pointers
        curr = head;

        while (curr) {

            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];

            curr = curr->next;
        }

        return m[head];
    }
};

