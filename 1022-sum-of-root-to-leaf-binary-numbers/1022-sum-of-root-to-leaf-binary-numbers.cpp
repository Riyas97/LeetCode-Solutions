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
    void printPreorder(TreeNode* node, int& val, int& sum)
    {
        if (node == NULL) {
            //cout << val << " ";
            //sum += val;
            return;
        }
        
        int add = node->val;
        val = val << 1;
        val += add;
        
        if (node->left == NULL && node->right == NULL) {
            sum += val;
        } else {
            /* then recur on left subtree */
            printPreorder(node->left, val, sum);

            /* now recur on right subtree */
            printPreorder(node->right, val, sum);    
        }
        
        val -= add;
        val = val >> 1;
        //cout << "post " << val << "\n";
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        int val = 0;
        printPreorder(root, val, sum);
        
        return sum;
    }
};