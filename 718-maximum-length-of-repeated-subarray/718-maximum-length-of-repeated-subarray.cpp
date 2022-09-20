class Solution {
public:
    
    vector<int> nums1, nums2;
    int n, m;
    
    int res = 0;
    
    int memo[1001][1001];
    
    int dp(int i, int j){
        
        if(i>=n or j>=m) return 0;
        
        if(memo[i][j] != -1)return memo[i][j];
        
        int temp1 = dp(i+1, j);
        int temp2 = dp(i, j+1);
        int temp3 = dp(i+1, j+1);
        
        res = max(res, temp1);
        res = max(res, temp2);
        res = max(res, temp3);
        
        if(nums1[i] == nums2[j]){    
            int temp = 1 + dp(i+1, j+1);
            res = max(res, temp);
            return memo[i][j] = temp;
        }
        
        return memo[i][j] = 0;
    }
    
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        this->nums1 = nums1;
        this->nums2 = nums2;
        n = nums1.size();
        m = nums2.size();
        
        memset(memo, -1, sizeof memo);
        
        int temp = dp(0, 0);
        
        return res;
        
    }
};