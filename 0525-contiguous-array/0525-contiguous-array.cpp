class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        mp[0] = -1;
        int cnt= 0 , ans(0);
        for(int i=0;i<n;++i){
            cnt += (nums[i]==0? -1 : 1);
            
            if(mp.count(cnt) > 0)
                ans = max(ans, i-mp[cnt]);

            if(mp.count(cnt) == 0) mp[cnt] = i;
        }
        return ans;
    }
    
};