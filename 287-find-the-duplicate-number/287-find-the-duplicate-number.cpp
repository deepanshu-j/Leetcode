class Solution {
public:
    
    vector<int> nums;
    int ans = -1;
    void recc(int idx){
        
        if(nums[idx] == -1){
            ans = idx;
            return;
        }

        int val = nums[idx];
        nums[idx] = -1;
        recc(val);
    }
    
    int findDuplicate(vector<int>& nums) {
        
        this->nums = nums;
        
        recc(0);
        
        return ans;
    }
};