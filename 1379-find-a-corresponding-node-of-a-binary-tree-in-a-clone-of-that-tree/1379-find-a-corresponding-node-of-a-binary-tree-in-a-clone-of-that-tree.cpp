/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* preOrder(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == NULL) {
            return NULL;
        }
        if (original == target) {
            return cloned;
        }
        TreeNode* ob = preOrder(original->left, cloned->left, target);
        if (ob != NULL) {
            return ob;
        }
        return preOrder(original->right, cloned->right, target);
    }
    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return preOrder(original, cloned, target);
    }
};