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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ans->val = 0;
        ListNode* prev = ans;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            ListNode* a1 = new ListNode();
            prev->next = a1;
            int sum = carry + l1->val + l2->val;
            carry = sum / 10;
            a1->val = sum % 10;
            prev = a1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            ListNode* a1 = new ListNode();
            prev->next = a1;
            int sum = carry + l1->val;
            carry = sum / 10;
            a1->val = sum % 10;
            prev = a1;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            ListNode* a1 = new ListNode();
            prev->next = a1;
            int sum = carry + l2->val;
            carry = sum / 10;
            a1->val = sum % 10;
            prev = a1;
            l2 = l2->next;
        }
        if (carry > 0) {
            ListNode* a1 = new ListNode();
            prev->next = a1;
            a1->val = carry;
            a1->next = NULL;
        } else {
            prev->next = NULL;
        }
        return ans->next;
    }
};