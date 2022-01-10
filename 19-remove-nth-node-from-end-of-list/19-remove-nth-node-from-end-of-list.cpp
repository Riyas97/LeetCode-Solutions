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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* d1 = head;
        ListNode* d2 = head;
        int size = 0;
        
        while (d1 != NULL) {
            d1 = d1->next;
            size++;
        }
        
        int where = size - 1 - n;
        
        if (where == -1) {
            return head->next;
        }
        
        int count = 0;
        
        while (count < where) {
            d2 = d2->next;
            count++;
        }
        ListNode* nex = (d2->next)->next;
        d2->next = nex;
        
        return head;
    }
};