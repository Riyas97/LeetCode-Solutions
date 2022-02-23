/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, int& psum, unordered_map<int,int>& u1, 
            unordered_map<int,unordered_set<int>>& u2, int& mcount) {
        if (node == NULL) {
            return;
        }
        
        int nsum = node->val;
        
        dfs(node->left, nsum, u1, u2, mcount);
        dfs(node->right, nsum, u1, u2, mcount);
        
        int ncount;
        
        if (u1.find(nsum) == u1.end()) {
            ncount = 1;
            u1[nsum] = ncount;
        } else {
            ncount = u1[nsum] + 1;
            u2[u1[nsum]].erase(nsum);
            u1[nsum] = ncount;
        }
        
        if (u2.find(ncount) == u2.end()) {
            unordered_set <int> us;
            us.insert(nsum);
            u2[ncount] = us;
        } else {
            u2[ncount].insert(nsum);
        }
        
        mcount = max(mcount, ncount);
        
        psum += nsum;
        
        return;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
     
        int nsum = 0;
        unordered_map<int,int> u1; 
        unordered_map<int,unordered_set<int>> u2; 
        int mcount = 0;
        dfs(root, nsum, u1, u2, mcount);
        
        unordered_set<int> us = u2[mcount];
        vector<int> ans;
        for (auto it = us.begin(); it != us.end(); it++) {
            ans.push_back(*it);
        }
        
        return ans;
    }
};