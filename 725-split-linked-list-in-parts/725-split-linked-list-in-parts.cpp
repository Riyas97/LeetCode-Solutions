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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int count = 0;
        ListNode* itr = head;
        while (itr != NULL) {
            count++;
            itr = itr->next;
        }
        if (k == 1) {
            ans.push_back(head);
            return ans;
        }
        if (k <= count) {
            int size = count / k;
            int first = count % k;
            int lcount = 0;
            ListNode* curr = head;
            while(lcount < k) {
                lcount++;
                int llcount = size;
                if (lcount <= first) {
                    llcount += 1;
                }
                ans.push_back(curr);
                while(llcount > 1) {
                    llcount--;
                    curr = curr->next;
                }
                ListNode* next = curr->next;
                curr->next = NULL;
                curr = next;
            }
        } else {
            ListNode* curr = head;
            while(k--) {
                if (curr != NULL) {
                    ListNode* next = curr->next;
                    curr->next = NULL;
                    ans.push_back(curr);
                    curr = next;
                } else {
                    ans.push_back(NULL);
                }
            }
        }
        return ans;
    }
};