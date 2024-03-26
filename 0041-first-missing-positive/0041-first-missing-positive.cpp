class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        bool isOnePresent = 0;
        for(auto &x: nums) if(x == 1) isOnePresent = true;
        if(!isOnePresent) return 1;
        // now we can use 1 or -1 in the array as we know 1 is not present //
        for(auto &x: nums) if(x<=0) x = 1;
        
        for(int i=0;i<n;++i){

            int val = abs(nums[i]);
            int idx = val-1;
            
            if(idx>=n or nums[idx] < 0){
                continue;
            } else nums[idx] *= -1;
            
        }
        // for(auto x: nums) cout<<x<<" ";
        for(int i=0;i<n;++i) if(nums[i] > 0) return i+1;
        return n+1;
    }
};