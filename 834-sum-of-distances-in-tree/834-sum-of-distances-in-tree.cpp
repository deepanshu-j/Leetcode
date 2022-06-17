#define rep(i,a,b) for(ll i=a ; i<(b) ; ++i )
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define all(x) x.begin(), x.end()
using ll=int;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;

class Solution {
public:
    
    vector<vi> tree; // adjList
    vector<bool> vis;
    vi dist; // dist represents dist of the "root" node from all the other nodes calculated in the first_dfs_call fn
    vi cnt;
    vector<int> res;
    ll tot_nodes;
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };

    map<pii, ll> memo; // the ans for the key={u,v} represents the answer for node u without considering u's child v //  

    ll find_cnt(ll node){
        vis[node]=1;
        ll ans=1;
        for(auto x: tree[node]){
            if(!vis[x])
            ans += find_cnt(x); 
        }
        return cnt[node]=ans;
    }

    ll first_dfs_call(ll node){ // to calculate the dist for the tree rooted at "root"

        vis[node]=1;
        ll ans = 0;
        for(auto x: tree[node]){
            if(!vis[x])
            ans += first_dfs_call(x)+cnt[x];
        }

        return dist[node]=ans;
    }

    void dfs(ll node, ll parent){
        // cout<<"Node: "<<node<<", Parent: "<<parent<<"\n";
        vis[node]=1;  

        // precomputing prefix and suffix //
        vi child;
        rep(i,0,tree[node].size())
        if(!vis[tree[node][i]])
        child.eb(tree[node][i]);

        ll sz=child.size();

        vi prefix(sz, 0), suffix(sz, 0);
        ll sum=0;
        rep(i,0,sz)
            prefix[i] = (i>0?prefix[i-1]:0)+dist[child[i]]+cnt[child[i]];

        for(ll i=sz-1; i>=0; --i)
            suffix[i] = (i+1<sz?suffix[i+1]:0)+dist[child[i]]+cnt[child[i]];

        // storing these in memo so that they can be used in inner reccursion //
        rep(i,0,sz){
            ll ans = 0;
            if(i>0)
            ans += (prefix[i-1]); 
            if(i+1<sz)
            ans += (suffix[i+1]);
            if(parent!=-1)
            ans += memo[{parent, node}]+(tot_nodes-cnt[node]);
            // ans += ;   

            memo[{node, child[i]}] =  ans ;

            // cout<<"Memo: parent:"<<node<<" , without child:"<<child[i]<<" ,val:"<<memo[{node, child[i]}]<<"\n";
        }

        // answer for this node //

        if(parent!=-1){
            res[node] = dist[node]; //+cnt[node]; // POE
            res[node] += (memo[{parent, node}] + (tot_nodes-cnt[node]));
        }

        for(auto x: tree[node]){
            if(!vis[x])
            dfs(x, node);
        }

    }

    void solve(int N, vector<vector<int>>& edges){
        ll n = N;

        tot_nodes = n;

        tree.resize(n+1);
        vis.resize(n+1, 0);
        dist.resize(n+1, 0);
        cnt.resize(n+1, 0);
        res.resize(n, 0);

        for(auto e: edges){
            ll u=e[0], v=e[1]; 
            tree[u].eb(v);
            tree[v].eb(u);
        }

        ll root = 0 ; // random root //

        ll temp = find_cnt(root);
        vis.clear();
        vis.resize(n+1, 0);
        temp = first_dfs_call(root);
        vis.clear();
        vis.resize(n+1, 0);
        dfs(root, -1);

        res[root] = dist[root];
        // rep(i,1,n+1)
        // cout<<"i: "<<i<<" , dist: "<<dist[i]<<"\n";

        // rep(i,1,n+1)
        // cout<<res[i]<<" ";
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        solve(N, edges);
        
        return res;
    }
};