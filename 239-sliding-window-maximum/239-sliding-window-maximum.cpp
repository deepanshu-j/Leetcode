class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // cp approach using set/multiset //
        vector<int> res;
        int n = nums.size();
        
        multiset<int> s;
        for(int i=0;i<k;++i)s.insert(nums[i]);
        
        int mx = *s.rbegin();
        res.emplace_back(mx);
        
        for(int i=k;i<n;++i){
         
            s.insert(nums[i]);
            int val = nums[i-k];
            auto itr = s.find(val);

            s.erase(itr);
            
            mx = *(s.rbegin());
            res.emplace_back(mx);
                
        }
        
        return res;
    }
};