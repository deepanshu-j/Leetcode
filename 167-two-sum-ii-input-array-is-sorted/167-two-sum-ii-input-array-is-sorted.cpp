class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        map<int, int> mp;
        
        for(int i=n-1;i>=0;--i){
            
            if(mp[target - numbers[i]]>0){
                vector<int> ans{i+1, mp[target-numbers[i]]+1};
                return ans;
            }
            mp[numbers[i]] = i;
        }
        return vector<int>();
    }
};