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
    bool ans  = 0;
    TreeNode* MainRoot;
    bool dfs2(TreeNode* root, int target){
        
        if(!root) return false;
        
        if(root->val == target) return true;
        
        if(target < root->val)
            return dfs2(root->left, target);
        
        return dfs2(root->right, target);
    }
    
    void dfs1(TreeNode* root){
        if(!root) return;
                
        if( k != 2*root->val )
            ans |= dfs2(MainRoot, k - (root->val));
        
        dfs1(root->left);
        dfs1(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        this->k = k; // Solution::k = k;
        
        this->MainRoot = root;
        dfs1(root);
        
        return ans;
    }
    
};