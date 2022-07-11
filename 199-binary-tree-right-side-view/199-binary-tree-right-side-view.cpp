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
    map<int,int> mp;
    void dfs(TreeNode* root, int lvl){
        mp[lvl] = root->val;
        
        if(root->left) dfs(root->left, lvl+1);
        if(root->right) dfs(root->right, lvl+1);

    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root)return vector<int>();
        
        dfs(root, 0);
        vector<int> ans;
        for(auto x: mp)ans.emplace_back(x.second);
        
        return ans;
    }
};