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
    ListNode* rotateRight(ListNode* head, int k) {
        int tlen = 0;
        ListNode* dup = head;
        while (dup != NULL) {
            tlen++;
            dup = dup->next;
        }
        //cout << tlen;
        if (k == 0 || tlen <= 1 || 
            k % tlen == 0) {
            return head;
        }
        if (k > tlen) {
            k %= tlen;
        }
        
        k = tlen - k;
        ListNode* dup1 = head;
        int count = 1;
        ListNode* prev;
        ListNode* ans;
        while (dup1 != NULL) {
            if (count == k) {
                ListNode* curr = dup1;
                dup1 = dup1->next;
                ans = dup1;
                curr->next = NULL;
                cout << dup1->val;
            } else {
                prev = dup1;
                dup1 = dup1->next;
            }
            count++;
        }
        prev->next = head;
        return ans;
    }
};