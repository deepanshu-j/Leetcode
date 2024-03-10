class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // n>m
        // (n+m)*log(min(m,n))
        // O(n+m)
        
        vector<int> res;
        unordered_set<int> mp;
        for(int &el: nums1) mp.insert(el);
        
        for(auto &x: nums2){
            if(mp.count(x) > 0){
                res.emplace_back(x);
                mp.erase(x);
            }
        }
        return res;
    }
};