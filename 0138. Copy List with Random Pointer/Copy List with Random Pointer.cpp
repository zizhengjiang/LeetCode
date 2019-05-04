/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return nullptr;
        Node *cur = head;
        
        while(cur) {
            Node *tmp = cur->next;
            cur->next = new Node(cur->val, nullptr, nullptr);
            cur->next->next = tmp;
            cur = tmp;
        }
        
        cur = head;
        while(cur) {
            if (cur->random) 
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        
        cur = head;
        Node *cCur = cur->next, *nHead = cur->next;
        while(cur) {
            cur->next = cur->next->next;
            cur = cur->next;
            cCur->next = cur ? cur->next : nullptr;
            cCur = cCur->next;
        }
        
        return nHead;
    }
};