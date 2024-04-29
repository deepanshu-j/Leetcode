class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int ans = 0;
        for(int bit = 0; bit<32; ++bit){
            
            int cnt = 0;
            for(auto num: nums){
                cnt += ((num>>bit) & 1);
            }
            
            ans += (((k>>bit)&1) != (cnt&1));
        }
        return ans;
    }
};