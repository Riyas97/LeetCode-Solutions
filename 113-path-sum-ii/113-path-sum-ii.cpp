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
    void inorder(TreeNode* node, vector<int>& vect, 
                 vector<vector<int>>& ans, int remaining) {
        if (node == NULL) {
            return;
        }
        vect.push_back(node->val);
        remaining -= (node->val);
        if (node->left == NULL && node->right == NULL) {
            if (remaining == 0) {
                ans.push_back(vect);
            }
        } else if (node->left == NULL) {
            inorder(node->right, vect, ans, remaining);
        } else if (node->right == NULL) {
            inorder(node->left, vect, ans, remaining);
        } else {
            inorder(node->left, vect, ans, remaining);
            inorder(node->right, vect, ans, remaining);
        }
        remaining += node->val;
        vect.pop_back();
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vect;
        vector<vector<int>> ans;
        inorder(root, vect, ans, targetSum);
        return ans;
    }
};