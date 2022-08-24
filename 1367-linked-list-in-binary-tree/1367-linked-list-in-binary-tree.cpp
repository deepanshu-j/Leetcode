/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* TreeRoot;
    ListNode* ListHead;
    
    bool ans  = false;
    
    bool dfs2(TreeNode* root, ListNode* head){
        
        if(!head)return true; // there's no element in list left to check // 
        if(!root)return false;
        
        if(root->val != head->val)return false;
        
        return dfs2(root->left, head->next) or dfs2(root->right, head->next);
        
    }
    
    
    void dfs1(TreeNode* root){
        
        if(!root)return;
        
        ans |= dfs2(root, ListHead);
        
        dfs1(root->left);
        dfs1(root->right);
    }
    
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        this->ListHead = head;
        this->TreeRoot = root;
        
        dfs1(root);
        
        return ans;
    }
};