class Solution{
    
    int size;
    vector<int> nums;
    
    int memo[1001];
    
    int countWays(int target){
            
        // base case //
        if(target == 0)return 1;
        
        if(memo[target]!=-1)return memo[target];
        
        // recursion //
        int countSubProblems = 0;
        for(int i = 0; i < size; ++i ){
            
            bool canTake = nums[i]<=target;
            
            if(canTake)
                countSubProblems += countWays(target - nums[i]);
            
        }
        
        return memo[target] = countSubProblems;
    }
    
    
    public:
    
    int combinationSum4(vector<int>& nums, int target) {
            
        this->nums = nums;
        this->size = nums.size();
        
        memset(memo, -1, sizeof memo);
        
        return countWays(target);
        
    }
    
};