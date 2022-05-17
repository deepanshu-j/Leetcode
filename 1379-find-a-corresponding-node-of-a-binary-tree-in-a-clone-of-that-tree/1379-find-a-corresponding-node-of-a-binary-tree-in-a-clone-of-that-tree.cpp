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
    
    TreeNode* ans=nullptr;
    void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // found the answer // 
        if(ans)return;
        
        if(!original)return;
        
        if(original==target)ans=cloned;
        
        dfs(original->left, cloned->left, target);
        dfs(original->right, cloned->right, target);
    }
 
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original, cloned, target);
        
        return ans;
    }
};