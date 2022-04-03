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
#define vi vector<int>
class Solution {
public:
    const int inf=1e8;
    map<TreeNode*, int> isBst;
    vi dp(TreeNode* root) {
        vi base_ans{1, root->val, root->val}; 
        if(!root->left and !root->right){
            isBst[root]=1;
            return base_ans; // for leaf node //       
        }
        
        int val=root->val;
        
        vi falsy{0,0,0};
        if(root->left and root->right){
            
            vi l=dp(root->left), r=dp(root->right);
    
            if(l[0] and r[0] and val>l[2] and val<r[1]){
                vi sub_ans{1, l[1], r[2]};
                isBst[root]=sub_ans[0];
                return sub_ans;
            }else{    
                isBst[root]=0;
                return falsy;
            }
            
        }else
        if(root->left and !root->right){
            vi l=dp(root->left);
            if(l[0] and val>l[2]){
                vi sub_ans{1, l[1], val};
                isBst[root]=sub_ans[0];
                return sub_ans;
            }else{
                isBst[root]=0;
                return falsy;
            }
        }
        else 
        if(!root->left and root->right){
            vi r=dp(root->right);
            if(r[0] and val<r[1]){
                vi sub_ans{1, val, r[2]};
                isBst[root]=sub_ans[0];
                return sub_ans;
            }else{
                isBst[root]=0;
                return falsy;
            }
        }   
        
        isBst[root]=0;
        return falsy;
    }
    
    map<TreeNode*, int> sum;
    int dp2(TreeNode* root){
        if(!root)return 0 ;
        return sum[root] = (root->val)+dp2(root->left)+dp2(root->right);
    }
    
    int res=-inf;
    void dp3(TreeNode *root){
        if(!root)return;
        
        if(isBst[root]) res=max(res, sum[root]);
        
        dp3(root->left);
        dp3(root->right);
    }
    
    int maxSumBST(TreeNode* root){
        vi temp = dp(root);
        int temp2=dp2(root);
        dp3(root);
        // return isBst[root->left->left];
        return max(0,res);
    }
    
};