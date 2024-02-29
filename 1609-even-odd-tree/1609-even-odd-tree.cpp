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
    bool isEvenOddTree(TreeNode* root) {
        
        
        queue<TreeNode*> q;
        q.push(root);
        int currentLevelCount = 1;
        int level = 0;
        
        function<bool(queue<TreeNode*>, int)> checkQueue;
        checkQueue = [&](queue<TreeNode*> queue, int currentLevel)->bool{
            
            if(currentLevel&1){ // dec  //
                int prev = 1e9;
                while(!queue.empty()){
                    TreeNode* top = queue.front();
                    queue.pop();
                    
                    if(prev <= top->val or (top->val)&1)
                        return false;
                    prev = top->val;

                }
                
            } else { // inc
                int prev = -1e8;
                while(!queue.empty()){
                    TreeNode* top = queue.front();
                    queue.pop();
                    
                    if(prev >= top->val or (top->val)%2==0)
                        return false;
                    prev = top->val;
                }
            }
            
            return true;
        };
        
        while(!q.empty()){
            
            int nextLevelCount = 0;
            vector<int> currentLevelNodes;
            if(not checkQueue(q, level)) return false;
            while(currentLevelCount --){
                TreeNode* tp = q.front();
                q.pop();
                // cout<<"level:"<<level<<" , "<<tp->val<<"\n";

                if(tp->left){
                    q.push(tp->left);
                    ++nextLevelCount;
                }
                if(tp->right){
                    q.push(tp->right);
                    ++nextLevelCount;
                }
            }
            
            currentLevelCount = nextLevelCount;
            ++level;
        }
        
        return true;
    }
};