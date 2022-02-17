#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        
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
};