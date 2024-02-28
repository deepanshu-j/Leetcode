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
    
    int mxdepth = 0;
    int val;
    
    void dfs(TreeNode* root, int depth){
        if(!root) return;
        if(mxdepth == depth){
            val = root->val;
        } else if(mxdepth<depth){
            mxdepth = depth;
            val = root->val;
        }
        
        dfs(root->right, depth+1);
        dfs(root->left, depth+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        val = root->val;
        dfs(root, 0);
        
        return val;
    }
};