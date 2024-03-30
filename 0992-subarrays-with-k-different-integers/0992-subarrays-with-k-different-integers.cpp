class Solution {
public:
    int atMostK(vector<int> &nums, int k){
        int ans = 0;
        int n = nums.size(), l = -1, r = 0;
        map<int,int> mp;
        while(r<n){
            mp[nums[r]]++;
            
            while( l<r && mp.size()>k){
                // keep removing left //
                ++l; mp[nums[l]]--; 
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                // ++l;
            } 
            ans += (r-l+1);
            ++r;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k)- atMostK(nums, k-1);
    }
};