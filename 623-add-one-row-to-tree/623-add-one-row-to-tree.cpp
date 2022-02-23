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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            struct TreeNode* node = new TreeNode(val, root, NULL);
            return node;
        }
        
        queue<tuple<TreeNode*, int>> q;
        q.push(make_tuple(root, 1));
        
        while(!q.empty()) {
            tuple<TreeNode*, int> tup = q.front();
            q.pop();
            TreeNode* node = get<0>(tup);
            int row = get<1>(tup);
            
            if (row >= depth) {
                break;
            }
            
            if (row == depth - 1) {
                struct TreeNode* n1 = new TreeNode(
                    val, node->left, NULL);
                struct TreeNode* n2 = new TreeNode(
                    val, NULL, node->right);
                node->left = n1;
                node->right = n2;
            } else {
                if (node->left != NULL) {
                    q.push(make_tuple(node->left, row+1));
                }
                if (node->right != NULL) {
                    q.push(make_tuple(node->right, row+1));
                }
            }
        }
        
        return root;
    }
};