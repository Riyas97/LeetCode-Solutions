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
    void bfs(TreeNode* node, int& sum, string& sofar) {
        if (node == NULL) {
            cout << sofar << "\n";
            int num = stoi(sofar);
            sum += num;
            return;
        }
        sofar.push_back('0' + node->val);
        if (node->left == NULL && node->right == NULL) {
            // leaf node
            int num = stoi(sofar);
            sum += num;
            sofar.pop_back();
            return;
        }
        if (node->left != NULL) {
            bfs(node->left, sum, sofar);
        }
        if (node->right != NULL) {
            bfs(node->right, sum, sofar);
        }
        sofar.pop_back();
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        string sofar = "";
        int ans = 0;
        bfs(root, ans, sofar);
        return ans;
    }
};