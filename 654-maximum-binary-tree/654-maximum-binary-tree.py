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
    
    TreeNode* recc(int i, int j, vector<int> &nums){
        if(i<0 or j>=nums.size() or i>=nums.size() or j<0 or i>j)return nullptr;
        
        if(i==j){ // leaf node 
            TreeNode* node=new TreeNode(nums[i]); 
            return node;
        }
        
        int mx=-1, idx=-1;
        for(int k=i;k<=j;++k){
            if(mx<=nums[k]){
                mx=nums[k];
                idx=k;
            }
        }
        assert(idx<nums.size() and idx>=0);
        TreeNode *left=recc(i, idx-1, nums), *right=recc(idx+1, j, nums);
        
        TreeNode* node =new TreeNode(nums[idx], left, right);
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recc(0, nums.size()-1, nums);
    }
};