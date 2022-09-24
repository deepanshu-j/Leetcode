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
        
        if(!root)return;
        
        int val = root->val;
        sum += val;
        if(sum == targetSum and !root->left and !root->right){
            ans = true;
            return;
        }
        
        dfs(root->left, sum);
        dfs(root->right, sum);
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        this->targetSum = targetSum;
        dfs(root, 0);
        
        return ans;
    }
};