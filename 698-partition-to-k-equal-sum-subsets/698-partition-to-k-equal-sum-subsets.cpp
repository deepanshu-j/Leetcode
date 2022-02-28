#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
#define eb emplace_back
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

class Solution {
public:
    
    int sum=0;
    int sz=-1;
    bool res=false;
    void dp(int n, vi &psets, int &k, vi &nums){
        // base case //
        if(n==sz){
            bool ok=1;
            rep(i,0,psets.size())
                if(psets[i]!=sum) ok=false;   
            if(psets.size()!=k)ok=false;
            
            if(ok){
                res=true;
            }
            
            return;
        }
        
        // recc //
        // try to put this nth element in all the sets we have created or add into a new set(if possible)
        
        if(res)return;
        
        
        // add it to some existing set //
        rep(i,0,psets.size()){
            
            if(psets[i]+nums[n] <= sum){
                psets[i] += nums[n];
                dp(n+1, psets, k, nums);
                psets[i] -= nums[n];
            }
            
        }
        // add into a new set if possible 
        if(psets.size()<k){
            psets.eb(nums[n]);
            dp(n+1, psets, k, nums);
            psets.pop_back();
        }
        
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> psets; // partioned sets //
        int tot_sum = accumulate(all(nums),0);
        if(tot_sum%k!=0)
            return false;
        
        sum = tot_sum/k;
        sz = nums.size();
        
        dp(0, psets, k, nums);
        
        return res;
    }
};