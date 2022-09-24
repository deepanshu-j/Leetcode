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
    vector<int> cur;
    vector<vector<int>> ans;
    
    
    void dfs(TreeNode* root, int target){
        
        if(!root) return;
        
        int val = root->val;
        cur.emplace_back(val);
        
        if(target +  val == targetSum and !root->left and !root->right){
            ans.emplace_back(cur);
        }
        
        dfs( root->left, target + val );
        dfs( root->right, target + val );
        cur.pop_back();
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        cur.reserve(5001);
        
        dfs(root, 0);
        
        return ans;
        
    }
};