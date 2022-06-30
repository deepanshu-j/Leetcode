using ll = long long;

#define all(x) begin(x),end(x)
#define inf LONG_MAX

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        ll l = *min_element(all(nums)), 
        r = *max_element(all(nums));
        
        auto f = [&](ll x)->ll{
            ll n = nums.size();
            ll ans = 0;
            for(ll i=0;i<n;++i){
                ans += abs(nums[i] - x);
            }  
            return ans;
        };
        
        ll ans  = 0;
        while(l<=r){
            ll x = (l+r)/2;
            
            if( f(x-1)>=f(x) and f(x)<=f(x+1) ){
                ans = x;
                break;
            }
            
            if(f(x-1)<=f(x) and f(x)<=f(x+1)){
                r = x;
            }
            else
            if(f(x-1)>=f(x) and f(x)>=f(x+1)){
                l = x;
            }
        }
        
        int res = (int)(f(ans));
        return res;
    }
};