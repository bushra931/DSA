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
    Node* dfs(Node* node,unordered_map<Node*,Node*>& cloned){
        if(cloned.count(node)) return cloned[node];
        Node* clone=new Node(node->val);
        cloned[node]=clone;
        for(Node* nbr:node->neighbors){
            clone->neighbors.push_back(dfs(nbr,cloned));
        }
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        unordered_map<Node*,Node*> cloned;
        return dfs(node,cloned);        
        
    }
};