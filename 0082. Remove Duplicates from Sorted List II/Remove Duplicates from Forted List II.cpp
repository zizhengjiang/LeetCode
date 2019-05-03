/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        
        while (cur) {
            while (cur->next && cur->val == cur->next->val) cur = cur->next;
            if (pre->next == cur) pre = cur;
            else pre->next = cur->next;
            cur = cur->next;
        }
        
        return dummy->next;
    }
};