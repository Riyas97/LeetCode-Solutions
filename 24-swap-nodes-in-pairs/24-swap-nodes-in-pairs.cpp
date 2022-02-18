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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dupt1 = head;
        if (dupt1 == NULL || dupt1->next == NULL) {
            return head;
        }
        //ListNode* nextNode = head->next;
        //head->next = NULL;
        //nextNode->next = head;
        
        ListNode* start = head->next;
        ListNode* prev = start;
        bool s = true;
        
        while (dupt1 != NULL && dupt1->next != NULL) {
            //cout << dupt1->val << dupt1->next->val << "\n";
            ListNode* nextNode = dupt1->next;
            ListNode* nextnext = nextNode->next;
            dupt1->next = nextnext;
            nextNode->next = dupt1;
            if (!s) {
                prev->next = nextNode;
            }
            s=false;
            prev = dupt1;
            dupt1 = dupt1->next;
            //cout << nextNode->val << "\n";
        }
        return start;
    }
};