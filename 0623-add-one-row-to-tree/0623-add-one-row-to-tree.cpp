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
    
    int depth, val;
    void dfs(TreeNode* root, int cur_depth){
        
        if(!root) return;
            
        if(cur_depth == depth - 1){
            
            TreeNode* new_left = new TreeNode(val, root->left, nullptr);
            TreeNode* new_right = new TreeNode(val, nullptr, root->right);
            
            root->left = new_left;
            root->right = new_right;
            
            return;
        }
        
        dfs(root->left, cur_depth+1);
        dfs(root->right, cur_depth+1);
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        this->depth = depth;
        this->val = val;
        
        if(depth == 1){
            TreeNode *new_root = new TreeNode(val, root, nullptr);             
            return new_root;
        }
        
        dfs(root, 1);
        
        return root;
    }
};