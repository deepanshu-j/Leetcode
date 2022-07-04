#define pii pair<int,int> 
#define ff first
#define ss second
class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        multiset<pii> s;
        for(int i=0;i<n;++i){
            s.insert({a[i],i});
        }
        
        int mn_candy_val[n];
        memset(mn_candy_val, -1, sizeof mn_candy_val); // -1 means unset
        int cnt = 1;
        
        for(pii x: s){
            int val = x.ff;
            int idx = x.ss;
            int atleast = 1;
            if(idx-1>=0 and a[idx]>a[idx-1]){
                // unset //
                atleast = max(atleast, 1+mn_candy_val[idx-1]);
            }
            
            if(idx+1<n and a[idx]>a[idx+1]){
                atleast = max(atleast, 1+mn_candy_val[idx+1]);
            }
            
            mn_candy_val[idx] = atleast;
        }
        int ans=0;
        for(int i=0;i<n;++i){
            // cout<<mn_candy_val[i]<<" ";
            ans += mn_candy_val[i];
        }
        
        return ans;
    }
};