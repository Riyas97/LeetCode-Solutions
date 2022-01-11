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
    void printPreorder(TreeNode* node, int& val, int& ans)
    {
        if (node == NULL) {
            return;
        }
        
        val++;
        
        if (node->left == NULL && node->right == NULL) {
            ans = max(ans, val);
        } else {
            /* then recur on left subtree */
            printPreorder(node->left, val, ans);

            /* now recur on right subtree */
            printPreorder(node->right, val, ans);    
        }
        
        val--;
    }
    
    
    int maxDepth(TreeNode* root) {
        int val = 0;
        int ans = 0;
        printPreorder(root, val, ans);
        return ans;
    }
};