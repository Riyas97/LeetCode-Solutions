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
    int findBottomLeftValue(TreeNode* root) {
        queue<tuple<TreeNode*, int>> q;
        q.push(make_tuple(root, 1));
        int k = 0;
        int ans = root->val;
        
        while(!q.empty()) {
            tuple<TreeNode*, int> curr = q.front();
            q.pop();
            TreeNode* node = get<0>(curr);
            int r = get<1>(curr);
            
            if (r != k) {
                k = r;
                ans = node->val;
            }
            
            if (node->left != NULL) {
                q.push(make_tuple(node->left, r+1));
            }
            if (node->right != NULL) {
                q.push(make_tuple(node->right, r+1));
            }
        }
        
        return ans;
    }
};