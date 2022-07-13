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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root)return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(nullptr);
        vector<int> cur;
        while(!q.empty()){
            auto fr = q.front();
            q.pop();
            
            if(!fr){
                
                ans.emplace_back(cur);
                cur.clear();
                
                if(q.empty()) break;
                
                q.push(nullptr);
                continue;
            }
            
            cur.push_back(fr->val);
            if(fr->left) q.push(fr->left);
            if(fr->right) q.push(fr->right);
        }
        
        return ans;
    }
};