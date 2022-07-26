/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(!root)return nullptr;
        
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        
        if(left and right)return root;
        
        if( root == p or root == q){
            return root;
        } 
        
        if(left and !right)return left;
        if(!left and right)return right;
        
        return nullptr;
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return lca(root, p, q);
        
    }
};