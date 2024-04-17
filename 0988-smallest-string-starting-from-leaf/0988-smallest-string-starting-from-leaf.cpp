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
    
    string cur = "";
    string best = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    void dfs(TreeNode* root){
        if(!root) return;
        cur +=('a' + root->val);
        
        
        if(!root->left and !root->right){ //leaf node    
            string rev = cur;
            reverse(rev.begin(), rev.end());
            if(best > rev) best = rev;
        }
        
        dfs(root->left);
        dfs(root->right);
        cur.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return best;
    }
};