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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root) return root;
        
        int val = root->val;
        
        TreeNode *left = nullptr, *right = nullptr; 
        
        if(val == p->val or val == q->val)return root;
        
        if(p->val < val or q->val < val)
            left = lowestCommonAncestor(root->left, p, q); 
        
        if(p->val > val or q->val > val)
            right = lowestCommonAncestor(root->right, p, q);

        if(left and right) return root;
        if(!left and right)return right;
        
        return left;
    }
};