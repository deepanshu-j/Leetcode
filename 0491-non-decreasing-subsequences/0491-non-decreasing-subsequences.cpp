class Solution {
public:
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        auto is_dec = [](vector<int> &a)->bool{
            if(a.size() <= 1) return 0;
            int sz = a.size();
            for(int i=0;i<sz-1;++i){
                if(a[i] > a[i+1]) return false;
            }
            return 1;
        };
        
        set<vector<int>> res;
        
        int n = nums.size();
        int lim = 1<<n;
        for(int mask = 1; mask<lim; ++mask){
            int sz = __builtin_popcount(mask);
            vector<int> a;
            
            for(int i=0;i<n;++i){
                if((mask>>i)&1){
                    a.push_back(nums[i]);
                }
            }
            
            if(is_dec(a)) res.insert(a);
        }
        
        vector<vector<int>> b(res.begin(), res.end());
        
        return b;
    }
};