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
    
    int targetSum;
    bool ans = false;
    
    void dfs(TreeNode* root, int sum){
        sum += (root->val);
        if(!root->left and !root->right){
            if(sum == targetSum) ans = true;
            return;
        }
        if(root->left) dfs(root->left, sum);
        if(root->right) dfs(root->right, sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root) return false;
        
        this->targetSum = targetSum;
        dfs(root, 0);
        
        return ans;
    }
};