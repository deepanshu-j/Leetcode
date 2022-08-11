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
    
    bool check(TreeNode* root, long mn, long mx){
        
        if(!root) return true;
        
        int val = root->val;
        if(val>=mx or val<=mn)return 0;
        
        return (check(root->left, mn, val)
               and check(root->right, val, mx)
               );
    }
    
    bool isValidBST(TreeNode* root) {
        
        return check(root, LONG_MIN, LONG_MAX);
    }
};