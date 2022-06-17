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
    map<TreeNode*, int> mp;
    int memo[1001][2][2];
    
    // iscovered = True means that node is already covered by its parent //
    // must = True means that node must be covered because its parent relies on him // 
    
    int dp(TreeNode* root, bool iscovered, bool must){ 
        
        if(!root)return 0;
           
        if(mp.count(root) == 0)
            mp[root] = mp.size();
        
        if(memo[mp[root]][iscovered][must]!=-1)return memo[mp[root]][iscovered][must];
        
        int ans=1e7;
        // Lets cover this node // 
        // must be covered // case handled here //
        ans=min(ans, 1+dp(root->left, 1, 0)+dp(root->right, 1, 0));
            
        if(!must){
            
            // choice to cover or not //
            if(iscovered){
                // dont need to put a camera here as its already covered but children aren't covered //
                ans = min(ans, dp(root->left, 0, 0) + dp(root->right, 0, 0) );
            }
            else{
                // now its not mandatory to cover this node but someone must cover this //
                // so case 1: either put a camera on this node itself // case already handled outside conditions
                
                // or case 2 : Atleast 1 child have a camera // how to make sure 
                // first of all there should be atleast one child //
                if(root->left or root->right){
                    // case 2.1 only left child 
                    if(root->left)
                    ans = min(ans, dp(root->left, 1, 1)+dp(root->right, 0, 0));
                    // case 2.2 only right child 
                    if(root->right)
                    ans = min(ans, dp(root->left, 0, 0)+dp(root->right, 1, 1));
                    // case 2.3 both the child 
                }
                if(root->left and root->right){
                    ans = min(ans, dp(root->left, 1, 1) + dp(root->right, 1, 1));
                }
                
            }
        }
        return memo[mp[root]][iscovered][must] = ans;
        
    }
    int minCameraCover(TreeNode* root) {
        
        memset(memo, -1, sizeof memo);
        
        
        return dp(root, 0, 0);
    }
};