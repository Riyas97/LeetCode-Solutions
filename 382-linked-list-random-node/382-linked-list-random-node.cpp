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
    vector<int> vect;
    bool isfirst = true;
    
    Solution(ListNode* head) {
        while (head != NULL) {
            vect.push_back(head->val);
            head = head->next;
        }    
    }
    
    int getRandom() {
        int size = vect.size();
        int num = rand() % size;
        return vect[num];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */