using ll = long long;
using pii = pair<ll,ll> ;

class Solution {
public:
    
    const int MOD = 1e9+7;
    map<ll, vector<pii> > mp;
    map<ll,ll> memo;
    ll dp(int root){
        
        ll ans = 1LL;
        
        if(memo.count(root) > 0 )return memo[root];
        
        for(auto x: mp[root] ){
            if(x.first == x.second)
            ans += (dp(x.first) * dp(x.second));
            else ans += ( 2LL* dp(x.first) * dp(x.second));
        }
        
        ans %= MOD; 
        return memo[root] = ans;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        set<ll> s;
        for(auto &x: arr) s.insert(x);
        
        int n = arr.size();
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                ll val = 1LL * arr[i] * arr[j];
                if(s.count(val)>0){
                    mp[val].push_back({arr[i], arr[j]});   
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;++i){
            ans = (0LL + ans + dp(arr[i]))%MOD;
        }
        
        return ans;
    }
};