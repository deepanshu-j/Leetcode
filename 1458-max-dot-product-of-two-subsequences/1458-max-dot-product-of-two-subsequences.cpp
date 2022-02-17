#define inf 0x3f3f3f3f
class Solution {
public:
    vector<int> nums1, nums2;
    int memo[501][501][2];
    int dp(int i, int j, bool must_take){
        // base case //
        if(i==-1 or j==-1){ // invalid cases //
            if(must_take)
            return -inf;
            else
            return 0;
        }
        
        int ans=0;
        
        if(memo[i][j][must_take]!=-1)return memo[i][j][must_take];
        
        // case 1: choose them both 
        int sub_problem1 = dp(i-1, j-1, false) + nums1[i]*nums2[j];
        
        // case 2: dont choose i 
        int sub_problem2 = dp(i-1, j, must_take);
            
        // case 3: dont choose j
        int sub_problem3 = dp(i, j-1, must_take);
            
        return memo[i][j][must_take] = max({sub_problem1, sub_problem2, sub_problem3});
    }
    
    int maxDotProduct(vector<int>& nums1_local, vector<int>& nums2_local) {
        nums1=nums1_local;
        nums2=nums2_local;
        memset(memo, -1, sizeof memo);
        
        return dp(nums1.size()-1, nums2.size()-1, 1);
    }
};