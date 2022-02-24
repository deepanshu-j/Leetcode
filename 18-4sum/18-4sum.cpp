#define pb push_back
#define eb emplace_back
using ll= long long;
typedef vector<int> vi;
class Solution {
public:
    set<vi> res;
    
    unordered_map<int, unordered_set<int> > memo;
    
    void ksum(vi& nums, int k, ll target, int start, int end, vi &ans){
        
        if(k==1){ 
            if(memo[start].count(target)>0){
                    ans.eb(target);
                        
                    res.insert(ans);
                    
                    ans.pop_back();
            }
            return;
        }
        
        
        // recc //
        
        for(int i=start;i<=end;++i){
            
            ans.eb(nums[i]);
            
            ll f = target-nums[i];
            ksum(nums, k-1, f, i+1, end, ans);
            
            ans.pop_back();
        }
        
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int k=4, start=0, end=nums.size()-1;
        vi ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i=end;i>=start;--i){
            
            if(i+1<nums.size()){
                memo[i] = memo[i+1];
            }
            
            memo[i].insert(nums[i]);
        }
        
        ksum(nums, k, target, start, end, ans);
        
        return vector<vi>(res.begin(), res.end());
    }
};