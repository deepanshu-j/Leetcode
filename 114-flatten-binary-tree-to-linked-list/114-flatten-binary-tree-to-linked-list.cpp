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
    void flatten(TreeNode* root) {
         
        TreeNode* head = root;
        
        while(head){
            
            TreeNode *right_most = head->left, *right_subtree = head->right;
            
            if(right_most==nullptr){
                head = head->right;
                continue;
            }
            
            // find the rightmost node of left subtree //
            while(right_most->right)
                right_most = right_most->right;
            
            
            right_most->right = right_subtree;
            head->right = head->left;
            head->left = nullptr;
            
            head = head->right;
        }
        
        // return root;
        
    }
};