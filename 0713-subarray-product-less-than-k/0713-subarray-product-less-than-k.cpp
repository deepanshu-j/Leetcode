class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // two pointer approach //
        int l = 0, r = 0, n = nums.size();
        
        int prdt(1), ans(0);
        while(r<n){
            prdt *= nums[r];
            while(l<=r and prdt >= k){
                // keep removing from left //
                prdt /= nums[l++];
            }
            ans += (r-l+1); // add in ans the good subarrays //
            ++r;
        }
        
        return ans;
    }
};