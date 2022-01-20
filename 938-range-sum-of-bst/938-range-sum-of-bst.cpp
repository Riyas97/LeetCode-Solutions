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
    void preorder(TreeNode* node, int& sum, int l, int h)
    {
        if (node == NULL)
            return;

        if (node->val >= l && node->val <= h) {
            sum += node->val;
        }

        /* then recur on left subtree */
        preorder(node->left, sum, l, h);

        /* now recur on right subtree */
        preorder(node->right, sum, l, h);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        preorder(root, sum, low, high);
        return sum;
    }
};