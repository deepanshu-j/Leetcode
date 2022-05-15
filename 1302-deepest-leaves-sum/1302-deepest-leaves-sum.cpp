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
    int max_depth=0;
    int sum=0;
    
    void dp(TreeNode* root, int depth){
        if(!root->left and !root->right){
            if(depth>max_depth){
                sum=0;
                max_depth=depth;
            }
            if(depth==max_depth) sum+=(root->val);
            
            return;
        }
        
        if(root->left)dp(root->left, depth+1);
        if(root->right)dp(root->right, depth+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(!root)return 0;
        
        dp(root, 0);
        
        return sum;
    }
};