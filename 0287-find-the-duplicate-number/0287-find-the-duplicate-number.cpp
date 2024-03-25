class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // cyclic sort //
        int n = nums.size();
        for(int i=0;i<n;){
            int val = nums[i];
            int idx = val-1;
    
            if(i+1 == val) {
                ++i; continue;
            }
            
            if(nums[idx] == idx+1){
                return val;
            } else {
                if(nums[idx] != nums[i])
                    swap(nums[idx], nums[i]);
                else return nums[i];
            }
        }
        
        for(int i=0;i<n;++i){
            if(i+1 != nums[i]) return nums[i];
        }
        return -1;
    }
};