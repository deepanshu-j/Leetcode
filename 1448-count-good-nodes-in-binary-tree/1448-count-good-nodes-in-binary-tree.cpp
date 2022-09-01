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
    
   
    int dp(TreeNode* root, int mx){
        if(!root)return 0;
        
        int ans=0;
        if(mx<=root->val) ++ans;
        ans += dp(root->left, max(mx, root->val));
        ans += dp(root->right, max(mx, root->val));
        
        return ans;
    }
    int goodNodes(TreeNode* root) {
        return dp(root, -1e6);
    }
};