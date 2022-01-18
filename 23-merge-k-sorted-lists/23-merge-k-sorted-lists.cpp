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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode();
        ListNode* iter = ans;
        iter->val = 0;
        //vector <int> vect (lists.size(), INT_MAX);
        
        while (true) {
            int mnum = INT_MAX;
            int ind = -1; 
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL) {
                    int val = lists[i]->val;
                    if (val < mnum) {
                        mnum = val;
                        ind = i;
                    }
                }
            }
            if (ind == -1) {
                break;
            }
            ListNode* l1 = new ListNode();
            l1->val = mnum;
            iter->next = l1;
            iter = iter->next;
            lists[ind] = lists[ind]->next;
        }
        
        return ans->next;
    }
};