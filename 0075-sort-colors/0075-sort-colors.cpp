class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        int low = 0, mid = 0, high = n;
        
        // 0...low-1 , low...mid-1, mid ...high-1, high ... n-1 //
        for(;mid<high;){
            
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                ++low, ++mid;
            } else if(nums[mid] == 1){
                ++mid;
            } else {
                swap(nums[mid], nums[high-1]);
                high--;
            }
            
        }
        // return nums;
    }
};