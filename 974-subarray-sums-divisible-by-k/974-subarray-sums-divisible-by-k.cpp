class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        map<int, int> mp;
        
        int sum=0; 
        int res=0;
        for(int i=0;i<n;++i){
            sum+=((k*4000+nums[i])%k);
            int sum_mod=sum%k;
            if(sum_mod==0)++res;
            
            res += mp[sum_mod];
            
            mp[sum_mod]++;
        }
        return res;
    }
};