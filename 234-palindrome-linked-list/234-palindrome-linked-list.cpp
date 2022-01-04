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
    bool isPalindrome(ListNode* head) {
        vector <int> rep;
        while (head != NULL) {
            rep.push_back(head->val);
            head = head->next;
        }
        
        
        for (int i = 0; i <= (rep.size() - 1) / 2; i++) {
            if (rep[i] != rep[rep.size() - 1 - i]) {
                return false;
            }
            cout << rep[i] << rep[rep.size() - 1 - i] << "\n";
        }
        return true;
    }
};