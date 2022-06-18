#include <bits/stdc++.h>
using namespace std;
using ll = int;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(ll i=a ; i<(b) ; ++i )
#define repb(i,a,b) for(ll i=b-1 ; i>=(a) ; --i )
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define debugvec(x) cout<<#x<<": [ ";\
        for(ll iii=0;iii<x.size();++iii)\
        if(iii<x.size()-1)cout<<x[iii]<<" ,";else cout<<x[iii];\
        cout<<" ]\n";
#define all(x) x.begin(), x.end()
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
#define inf 0x3f3f3f3f
const ll MOD= 998244353;

vector<vector<int>> solve(int n, vector<vector<int>> &A){
    
    vector<pii> a(n), ans;
    
    for(int i = 0; i < n; ++i)
        a[i] = {A[i][0], A[i][1]};
    
    
    sort(all(a), [](pii &l, pii &r){
        if(l.ss==r.ss)return l.ff<r.ff;
        return l.ss<r.ss;
    });

    pii curr = {inf, inf+1};

    for(int i=n-1;i>=0;--i){
        if((a[i].ss-1>=curr.ff and a[i].ss-1<curr.ss) or (a[i].ss == curr.ff)){
            // extend
            curr.ff = min(curr.ff, a[i].ff);
            curr.ss = max(curr.ss, a[i].ss);
        }else{
            ans.pb(curr);
            curr = a[i];
        }
        
    }
    if(ans.size()>0 and ans.back()!=curr)
    ans.pb(curr);
    sort(all(ans));
    
    vector<vector<int>> res;
    for(pii x: ans){
        if(x.ff!=inf)
            res.pb({x.ff, x.ss});
        // cout<<x.ff<<" "<<x.ss<<"\n";
    }
    return res;
}

class Solution {    
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        return solve(A.size(), A);
    }
};