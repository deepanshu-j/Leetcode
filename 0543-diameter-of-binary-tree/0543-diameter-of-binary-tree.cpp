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
    int mx = 0;
    
    using pii = pair<int,int>;
    
    int depth(TreeNode* root){
        if(root == NULL) return 0;
        
        int depthLeft = depth(root->left);
        int depthRight = depth(root->right);
        int depthMax = max(depthLeft, depthRight);
        mx = max(mx, 1 + depthLeft + depthRight);
        return 1+depthMax;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        depth(root);
    
        return mx-1;
    }
};