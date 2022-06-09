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
    int k;
    TreeNode* root;
    bool ok=0;
    
    bool search(TreeNode* node, int target){
        
        if(!node)return 0;
        
        int val = node->val;
        
        if(val==target)return true;
        
        if(val<target)return search(node->right, target);
        
        return search(node->left, target);
        
    }
    
    void dfs(TreeNode* node){
        
        if(!node)return;
        
        if( k!= (2*(node->val)))
        ok |= search(root, k-(node->val));
        
        dfs(node->left);
        dfs(node->right);
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        Solution::k=k;
        Solution::root = root;
        
        dfs(root);
        
        // cout<<search(root, 3)<<"\n"<<search(root, 1)<<"\n";
        
        return ok;
    }
};