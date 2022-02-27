#define inf 0x3f3f3f3f
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
    
    // Every node must be either covered by 1. its parent or 2. Itself or 3. Atleast one of its direct child //
    
    // Every node will be either already covered by its parent // then we will have a choice to put a camera on the node or its child 
    // If a node is not already covered by its parent then  it must be covered by it direct child or itself //

    map<pair<TreeNode*, bool>, int> memo; 
    int dp(TreeNode* root, bool covered){
        
        // base case //
        // if(!root){
        //     return inf;
        // }
        
        if(!root->left and !root->right){ // leaf node
            if(covered)
                return 0;
            else 
                return 1;
        }
        
        
        auto key = make_pair(root, covered);
        if(memo.find(key)!=memo.end())return memo[key];
        
        // recc //
        
        int ans=inf;
        if(1){
        // if(not covered){
            // Case 1: cover it by itself //
            ans = min(ans, 1 + 
                      (root->left ? dp(root->left, true) : 0 ) + 
                      (root->right ? dp(root->right, true) : 0 ) );
            
            // Case 2: cover by atleast 1 of its child //
            int sub=inf;
            
            // Case 2.1: Place only on left child // It will have atleast one child as its not a laef node // leaf node is handled in base case //
            if(root->left){
                int var = 1 + 
                    (root->left->left ? dp(root->left->left, true) : 0) +
                    (root->left->right ? dp(root->left->right, true) : 0) +
                    (root->right ? dp(root->right, false) : 0 )
                    ;
                
                sub= min(sub, var);
            }
            
            // Case 2.2: Place only on right child 
            if(root->right){
                int var = 1 + 
                    (root->right->left  ? dp(root->right->left, true)  : 0) +
                    (root->right->right ? dp(root->right->right, true) : 0) +
                    (root->left ? dp(root->left, false) : 0 )
                    ;
                
                sub = min(sub, var);
            }
            
            // Case 2.3: place on both left and right childs  
            if(root->left and root->right){
                int var = 2 + 
                    (root->left->left   ? dp(root->left->left, true)   : 0) +
                    (root->left->right  ? dp(root->left->right, true)  : 0) +
                    (root->right->left  ? dp(root->right->left, true)  : 0) +
                    (root->right->right ? dp(root->right->right, true) : 0) ;
                sub= min(sub, var);
            }
            
            ans = min(ans, sub);
        }
        
        if(covered)
        {
            ans = min(ans, ( root->left ? dp(root->left, false) : 0 )  + 
                            ( root->right ? dp(root->right, false) : 0) 
                     );
        }
        
        return memo[key] = ans;        
    }
    
    int minCameraCover(TreeNode* root) {
        if(!root)return 0;
        return dp(root, false);
    }
};