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
    bool preorder(TreeNode* node, int k, 
                      unordered_set<int>& us) {
        if (node == NULL)
            return false;

        if (us.find(k - node->val) != us.end()) {
            return true;
        }
        us.insert(node->val);

        return preorder(node->left, k, us) || 
            preorder(node->right, k, us);

    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> us;
        return preorder(root, k, us);
    }
};