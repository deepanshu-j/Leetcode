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
    int ans = 0;
    void dfs(TreeNode* root, map<int,int>& mp){
         
        int val = root->val;

        bool added = 0;
        if(mp[val] == 0){
            mp[val]++;
            added = 1;
        }else
        if(mp[val] == 1) mp.erase(val);
        
        
        if(!root->left and !root->right){
            ans += (mp.size()<=1);
            if(added) mp.erase(val);
            else mp[val]++;
            
            return;
        }
        
        if(root->left) dfs(root->left, mp);
        if(root->right) dfs(root->right, mp);
        
        // remove the changes //
        if(added) mp.erase(val);
        else mp[val]++;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> mp;
        dfs(root, mp);
        
        return ans;
    }
};