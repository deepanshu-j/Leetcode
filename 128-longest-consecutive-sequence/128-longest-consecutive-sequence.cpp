class Solution {
public:
    int ans = 0;
    unordered_map<int,int> mp, done;
    int dp(int x){
        if(done[x])return mp[x];
        if(mp.count(x)==0)return 0;
        done[x] = 1;
        return mp[x] = 1+dp(x+1);
    }
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
    
        for(auto x: nums)mp[x]++;
        
        for(auto x: nums){
            ans = max(ans, dp(x)); 
        }
        return ans;
    }
};