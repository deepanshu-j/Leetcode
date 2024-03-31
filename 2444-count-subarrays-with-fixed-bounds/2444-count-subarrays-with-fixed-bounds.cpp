class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0, jbad = -1, jmin = -1, jmax = -1, n = nums.size();
        for(int i=0;i<n;++i){
            if (nums[i]<minK or nums[i]>maxK) jbad = i;
            if (nums[i] == minK) jmin = i;
            if (nums[i] == maxK) jmax = i;
            ans += max(0LL, min(jmin, jmax) - jbad);
        }
        return ans;
    }
};