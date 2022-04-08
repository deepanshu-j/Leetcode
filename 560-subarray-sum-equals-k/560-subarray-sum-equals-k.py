class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, res=0;
        int n=nums.size();
        
        map<int, int> mp;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            res+=mp[sum-k];
            if(sum==k)++res;
            ++mp[sum];
        }
        
        return res;
    }
};