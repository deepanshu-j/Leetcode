class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(auto x: nums) freq[x]++;
        int mx = *max_element(freq.begin(), freq.end());
        int ans = 0;
        for(auto x: freq) if(x == mx) ans += x;
        return ans;
    }
};