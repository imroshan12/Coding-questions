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
    void deleteNode(ListNode* node) {
        ListNode *it = node;
        while (it) {
            it->val = it->next->val;
            if(!it->next->next)
                it->next = nullptr;
            it = it->next;
        }
    }
};