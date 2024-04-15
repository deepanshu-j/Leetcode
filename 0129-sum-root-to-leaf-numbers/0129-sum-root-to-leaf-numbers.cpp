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
    void sumNumbers(TreeNode* root,int num,int *ans) {
        
        if(!root->left&&!root->right){num=num*10+root->val;*ans+=num;return;}
        if(!root->left&& root->right)
        {sumNumbers(root->right,10*num+root->val,ans);}
        if(!root->right && root->left)
        {sumNumbers(root->left,(10*num)+root->val,ans);}
        if(root->left&&root->right)
        {
            sumNumbers(root->left ,(10*num)+root->val,ans);
            sumNumbers(root->right,(10*num)+root->val,ans);
        }
    }
        
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        int a=0;
        int *ans=&a;
        sumNumbers(root,0,ans);
            return *ans;
    }
};