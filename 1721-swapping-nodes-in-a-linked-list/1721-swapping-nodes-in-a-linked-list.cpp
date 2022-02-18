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
    /*
    Jist: swap two nodes:
    onr would be kth node and another would 
    be n-kth node
    */
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* l1 = head;
        ListNode* l2 = head;
        k--;
        
        while(k > 0) {
            l1 = l1->next;
            k--;
        }
        
        // save kth node
        ListNode* kth = l1;
        l1 = l1->next;
        //cout << kth->val;
        
        while (l1 != NULL) {
            l1 = l1->next;
            l2 = l2->next;
        }
        
        //cout << l2->val;
        
        // swap n-kth and kth node
        //swap(kth, l2);
        int temp = kth->val;
        kth->val = l2->val;
        l2->val = temp;
        
        return head;
    }
};