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
using vi = vector<int>;
class Solution {
public:
    
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root)return vi();
        queue<TreeNode*> q;
        
        vi ans;
        
        int cur = -1;
        int lvl = 0;
        
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()){
            auto fr = q.front();
            q.pop();
            
            if(fr == nullptr){
                ans.emplace_back(cur);
                ++lvl;
                if(!q.empty())q.push(nullptr);
                
                continue;
            }
        
            cur = fr->val;
            if(fr->left)q.push(fr->left);
            if(fr->right)q.push(fr->right);
            
        }
        
        
        return ans;
    }
};