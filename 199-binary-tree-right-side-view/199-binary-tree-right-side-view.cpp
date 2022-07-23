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
    vector<int> right_view;
    
    void dfs(TreeNode* root, int depth){
        
        if(!root)return;
        
        if(right_view.size()<depth+1)
            right_view.emplace_back(root->val);
        else
            right_view[depth] = root->val;
        
        
        if(root->left)
        dfs(root->left, depth+1);
        
        if(root->right)
        dfs(root->right, depth+1);
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        
        dfs(root, 0);
        
        return right_view;
    }
};