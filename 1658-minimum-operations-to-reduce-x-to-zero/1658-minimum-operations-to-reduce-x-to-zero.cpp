class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        // longest subarray with sum = accumulate(nums) - x
        int n=nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        
        if(target==0)return n;
        
        map<int,int> mp; // prefix at what index//
        mp[0]=-1;
        int pre_sum = 0;
        int len=0;
        for(int i=0;i<n;++i){
            // i represents where the subarray will end //
            pre_sum += nums[i];
            int f = pre_sum - target;
            if(pre_sum==target){
                len = max(len, i+1);
            }
            else
            if(mp.find(f)!=mp.end()){
                // cout<<"i:"<<i<<"\n";
                // cout<<"i-mp[f]:"<<i-mp[f]<<"\n";
                len = max(len, i-mp[f] ); 
            }
            
            mp[pre_sum] = i;
        }
        
        // if(target==0){
        //     cout<<target<<"\n";
        //     len = max(len, n);
        // }
        
        return ((len==0)?-1:(n-len));
    }
};