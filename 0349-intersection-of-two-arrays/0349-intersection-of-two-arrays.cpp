class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // n>m
        // (n+m)*log(min(m,n))
        // O(n+m)
        
        vector<int> res;
        set<int> mp;
        for(int &el: nums1) mp.insert(el);
        
        sort(nums2.begin(), nums2.end());
        int mn = -1;
        for(auto &x: nums2){
            if(x > mn and mp.count(x) > 0){
                res.emplace_back(x);
                mn = x;
            }
        }
        return res;
    }
};