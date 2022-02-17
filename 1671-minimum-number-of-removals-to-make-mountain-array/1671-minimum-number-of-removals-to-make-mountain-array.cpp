#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==0)return 0;
        
        vector<int> ans;
        ans.eb(nums[0]);
        
        for(int i=1;i<n;++i){
            if(nums[i]>ans.back()){
                ans.eb(nums[i]);
            }else{
                int idx = lower_bound(all(ans), nums[i])-ans.begin();
                assert(idx<ans.size());
                ans[idx] = nums[i]; 
            }
        }
        
        return ans.size();
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        
        int res=0;
        int n = nums.size();
        for(int i=0;i<n;++i){
            
            /// let i be the pivot => a[i-1] < a[i] > a[i+1] ///
            vector<int> inc; /// increasing left part ///
            vector<int> dec; /// decreasing right part ///
            
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i])
                    inc.eb(nums[j]);
            }
            
            for(int j=i+1;j<n;++j){
                if(nums[j]<nums[i])
                    dec.eb(nums[j]);
            }
            
            if(dec.size())
            reverse(all(dec));
            
            if(inc.size() and dec.size()){
                int ans = 1+lengthOfLIS(inc) + lengthOfLIS(dec);
                res= max(res, ans);
            }
        }
        return n-res;
    }
};