class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> v { -1000000 };
        
        for(auto &x: nums){
            
            if(x > v.back() ){
                v.emplace_back(x);
                continue;
            }
            
            auto it = lower_bound(v.begin(), v.end(), x);
            int idx = it - v.begin();
            
            v[idx] = x;
            
        }
        
        int mx = v.size() - 1;        
        return mx;
    }
};