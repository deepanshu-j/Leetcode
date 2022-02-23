// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans;
//         int n=nums.size();
        
//         for(int i=0;i<n;++i){
//             int f = target-nums[i];
//             // auto itr = lower_bound(nums.begin()+(i+1), nums.end(), f);
//             int idx = lower_bound(nums.begin(), begin(nums)+i, f) - begin(nums);

//             if(idx<n){
                
//                 ans.push_back(i);
//                 ans.push_back(idx);
//                 return ans;
//             }
//         }
        
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        
        map<int, int> s;
        for(int i=0;i<n;++i){
            int f=target-nums[i];
            if(s.count(f)>0){
                ans.push_back(i);
                ans.push_back(s[f]);
                return ans;
            }
            s[nums[i]]=i;
        }
        
        return ans;
    }
};