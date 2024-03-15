class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int zero_cnt = 0;
        int n = nums.size();
        
        vector<int> pre_zero(n, 0), suf_zero(n, 0);
        
        vector<int> ones_index;
        for(int i=0;i<n;++i){
            zero_cnt += ( nums[i] == 0);
            pre_zero[i] = zero_cnt;

            if(nums[i] == 1){
                zero_cnt = 0;
                ones_index.push_back(i);
            }
        }
        
        zero_cnt = 0;
        for(int i=n-1;i>=0;--i){
            zero_cnt += (nums[i] == 0);
            suf_zero[i] = zero_cnt;
            if(nums[i] == 1){
                zero_cnt = 0;
            }
        }
        
        int sz = ones_index.size(), ans = 0;
        
        // if(sz == 0){
        //     ans = (n*(n+1))/2;
        //     return ans;
        // }
        if(goal == 0){
            for(int i=0;i<n;){
                if(nums[i] ==1 ){
                    ++i; continue;
                }
                int j = i;
                int cnt = 0;
                while(j<n and nums[j] == 0) ++j, cnt++;
                ans += (cnt * (cnt+1))/2;
                i = j;
            }
            return ans;
        }
        
        for(int i=0;i<sz;++i){
            int l = ones_index[i];
            if(i+goal-1>=sz) return ans;
            int r = ones_index[i + goal-1];
            ans += (pre_zero[l] + 1) * ( suf_zero[r] + 1);
        }
        
        return ans;
    }
};