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
    
    int dfs(TreeNode* root){
        
        if(!root)return 0;
        
        int left_cnt = dfs(root->left);
        int right_cnt = dfs(root->right);
        if( left_cnt == 0 )
            root->left = nullptr;
        
        if( right_cnt == 0 )
            root->right = nullptr;
        
        int ans = left_cnt + right_cnt;
        if(root->val == 1) ++ans;
            
        return ans;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        if (dfs(root) == 0)return nullptr;
        return root;
    }
};