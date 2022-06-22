#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define debugvec(x) cout<<#x<<": [ ";\
        for(ll iii=0;iii<x.size();++iii)\
        if(iii<x.size()-1)cout<<x[iii]<<" ,";else cout<<x[iii];\
        cout<<" ]\n";
class Solution {
public:
    
    int maximumWhiteTiles(vector<vector<int>>& a, int cl) {
        
        sort(a.begin(), a.end());
        
        int n = a.size();
        long long ans=0;
        
        vector<long long> p(n, 0);
        for(int i=0;i<n;++i)p[i] = a[i][1]-a[i][0]+1;
        for(int i=1;i<n;++i) p[i] += p[i-1];
        
        for(int i=0;i<n;++i){
            
            int startTile = a[i][0];
            int endTile = startTile + cl - 1;
            // debug(endTile)
            auto bs = [&](int start)->int{
        
                int l=start, r=n-1;    
                // l -> the tile index with which it will have an overlap
                // r -> the tile index with which it will not have an overlap
                
                if(a[r][0]<=endTile)return r;
                if(endTile<=a[l][1])return l;
                

                while(l+1<r){
                    int m = (l+r)/2;
                    // debug(m)
                    if(a[m][0]<=endTile and endTile<=a[m][1]){
                        return l=m;
                    }else
                    if( a[m][1]<endTile ) l = m;
                    else
                    if(a[m][0]>endTile) r = m;

                }
                return l;
            };
            
            // find the index of a which will have the last overlap with out carpet //
            
            int idx = bs(i);
            long long sol = 0;
            if(idx-1>=0) sol += p[idx-1];
            if(i-1>=0) sol -= p[i-1];
            
            // add overlap with this tile at idx //
            if(endTile>a[idx][1]) sol += (a[idx][1]-a[idx][0]+1);
            else sol += ( min(a[idx][1], endTile) - a[idx][0] +1  ); //poe
            // debug(idx)
            // debug(sol)
            // int sol = pre[idx-1]
            ans = max(ans, sol);
        }
        return ans;
    }
};