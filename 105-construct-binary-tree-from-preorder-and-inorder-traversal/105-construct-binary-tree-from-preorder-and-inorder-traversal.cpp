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
    vector<int> preorder, inorder;
    TreeNode* formTree(int pre_i, int pre_j, int ino_i, int ino_j){
        
        // cout<<"pre_i:"<<pre_i<<" , "<<"pre_j:"<<pre_j<<" , "
        //     <<"ino_i:"<<ino_i<<" , "<<"ino_j:"<<ino_j<<"\n";
        if(pre_i>pre_j)return nullptr;
        
        if(pre_i==pre_j){

            TreeNode* node = new TreeNode(preorder[pre_i]);    
            return node;
        }
        
        int root_val = preorder[pre_i];
        int root_idx=ino_i;
        
        while(inorder[root_idx]!=root_val)
            ++root_idx;
        
        int tot = pre_j - pre_i + 1;
        int l = root_idx - ino_i;
        int r = tot-l-1;
        
        TreeNode* leftSubTree = formTree(pre_i+1, pre_i+l,ino_i, root_idx-1);
        TreeNode* rightSubTree = formTree(pre_i+l+1, pre_j, root_idx+1, ino_j);
        
        TreeNode* node = new TreeNode(preorder[pre_i], leftSubTree, rightSubTree);  
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        this->preorder = preorder;
        this->inorder = inorder;
        
        int n = preorder.size();
        return formTree(0, n-1, 0, n-1);
    }
};