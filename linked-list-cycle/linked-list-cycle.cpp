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
    bool hasCycle(ListNode *head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        
        while (temp1 && temp2 && temp1->next) {
            temp1 = temp1 -> next -> next;
            temp2 = temp2 -> next;
            if (temp1 == temp2) {
                return true;
            }
            
        }
        return false;
    }
};