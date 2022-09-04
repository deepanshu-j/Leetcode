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
    
    multiset<vector<int>> ans;
    void dfs(TreeNode* root, int depth, int shift){
        
        if(!root)return;
        
        vector<int> sub{ shift, depth, root->val };
        
        ans.insert(sub);
        
        dfs(root->left, depth+1, shift - 1);
        dfs(root->right, depth+1, shift + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        dfs(root, 0, 0);
        
        vector<vector<int>> res;
        int prev = -1e8;
        for(auto &x: ans){
            if(prev != x[0]){
                res.push_back(vector<int>());
                res.back().push_back( x[2] );
            }else
                res.back().push_back( x[2] );
            prev = x[0];
        }
        
        return res;
    }
};