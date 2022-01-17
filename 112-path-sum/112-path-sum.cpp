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
    void preorder(TreeNode* node, int& sum, int target, bool& ans)
    {
        if (node == NULL) {
            return;
        }
            
        sum += node->val;
        
        /* first print data of node */
        //cout << node->data << " ";

        if (node->left == NULL && node->right == NULL) {
            if (sum == target) {
                ans = true;
            }
            sum -= node->val;
            return;
        }
        
        /* then recur on left subtree */
        preorder(node->left, sum, target, ans);
    
        /* now recur on right subtree */
        preorder(node->right, sum, target, ans);
        
        sum -= node->val;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        int sum = 0;
        preorder(root, sum, targetSum, ans);
        return ans;
    }
};