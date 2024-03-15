class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, 1);
        
        int prev_prdt = 1;
        for(int i=1;i<n;++i){
            prev_prdt *= nums[i-1];
            ans[i] = prev_prdt;
        }
        
        int next_prdt = 1;
        
        for(int i=n-2;i>=0;--i){
            next_prdt *= nums[i+1];
            ans[i] *= next_prdt;
        }
        
        return ans;
    }
};