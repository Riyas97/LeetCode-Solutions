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
        ListNode* n1 = node->next;
        while (n1 != NULL) {
            node->val = n1->val;
            n1 = n1->next;
            if (n1 != NULL) {
                node = node->next;
            } else {
                node->next = NULL;
            }
            
        }
    }
};