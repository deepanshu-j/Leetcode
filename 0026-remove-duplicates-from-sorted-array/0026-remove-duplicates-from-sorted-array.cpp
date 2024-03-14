class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         // 1 1 1 2 2 3 3 3    
        int i = 1, j = 1;
        int n = nums.size();
        int prev = nums[0];
        while(j<n){
            
            if(nums[j] > prev){
                prev = nums[j];
                nums[i++] = prev;
            }
            
            ++j;
        }
        
        return i;
    }
};