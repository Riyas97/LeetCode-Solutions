/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(Node* node)
    {
        queue<tuple<Node*, int>> qu;
        int row = 0;
        qu.push(make_tuple(node, row));
        Node* prevNode = NULL;
        int prevRow;
        while(!qu.empty()) {
            tuple<Node*, int> tu = qu.front();
            qu.pop();
            Node* pNode = get<0>(tu);
            int pRow = get<1>(tu);
            if (pNode != NULL) {
                if (prevNode != NULL) {
                    if (prevRow == pRow) {
                        prevNode->next = pNode;
                    }
                } 
                if (pNode->left != NULL) {
                    qu.push(make_tuple(pNode->left, pRow+1));
                }
                if (pNode->right != NULL) {
                    qu.push(make_tuple(pNode->right, pRow+1));
                }
                prevNode = pNode;
                prevRow = pRow;
            }
        }
    }
    
    
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        bfs(root);
        return root;
    }
};