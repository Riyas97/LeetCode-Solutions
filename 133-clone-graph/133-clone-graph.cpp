/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }
        
        unordered_map <Node*, Node*> um;
        queue<Node*> q;
        q.push(node);
        
        Node* n = new Node(node->val);
        um[node] = n;
        
        while(!q.empty()) {
            Node* p1 = q.front();
            q.pop();
            
            // BFS
            for (int i = 0; i < p1->neighbors.size(); i++) {
                Node* n1 = p1->neighbors[i];
                if (um.find(n1) == um.end()) {
                    Node* n2 = new Node(n1->val);
                    um[n1] = n2;
                    q.push(n1);
                }
                um[p1]->neighbors.push_back(um[n1]);
            }
        }
        
        return n;
    }
};