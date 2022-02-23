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
    unordered_map<Node*, Node*> mp;
    
    unordered_map<Node*, int> vis;
    void dfs_1(Node* node){
        
        if(vis[node]>0)return;
        vis[node]++;
        
        Node* new_node = new Node(node->val);
        mp[node] = new_node;
        
        for(auto x: node->neighbors){
            if(!vis[x]){
                dfs_1(x);
            }
        }
    }
    
    void dfs_2(Node* node){
        
        if(vis[node]>0)return;
        vis[node]++;
        
        // build the connections //
        vector<Node*> new_neighbors;
        for(auto x: node->neighbors){
            new_neighbors.emplace_back(mp[x]);
        }
        
        mp[node]->neighbors = new_neighbors;
        
        for(auto x: node->neighbors){
            if(!vis[x]){
                dfs_2(x);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        
        if(!node)return node;
        
        dfs_1(node);
        
        vis.clear();
        
        dfs_2(node);
        
        return mp[node];
    }
};