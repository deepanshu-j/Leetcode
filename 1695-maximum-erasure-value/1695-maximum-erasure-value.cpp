class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums){
        
        map<int,int> mp;
        int n=nums.size();
        int i=0, ans=*max_element(nums.begin(), nums.end()), sum=0;
        for(int j=0;j<n;++j){
            sum += nums[j];
            mp[nums[j]]++;
            
            while(mp[nums[j]]>1){
                mp[nums[i]]--;
                sum -= nums[i];
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                
                ++i;
            }
            
            ans=max(ans, sum);
        }
        return ans;
    }
};