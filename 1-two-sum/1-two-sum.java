import java.util.HashMap;
class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        int[] ans = new int[2];
        HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for(int i=0; i<nums.length; ++i){
            int f= target-nums[i];
            if(mp.get(f)!=null){ 
                
                ans[0] = i;
                ans[1] = mp.get(f);
                
                return ans;
            }
            
            mp.put(nums[i], i);
        }
        return ans;
    }
}