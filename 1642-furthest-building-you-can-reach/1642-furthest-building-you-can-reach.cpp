#define vi vector<int> 
#define pb push_back
#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define debugvec(x) cout<<#x<<": [ ";\
        for(int iii=0;iii<x.size();++iii)\
        if(iii<x.size()-1)cout<<x[iii]<<" ,";else cout<<x[iii];\
        cout<<" ]\n";
class Solution {
public:
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        vi a = heights;
        int n = heights.size();
      
        auto check = [&](int x)->bool{

            vi diff;
            for(int i=0;i<x;++i){
                if(a[i+1]-a[i]>0)
                    diff.pb(a[i+1]-a[i]);
            }
            sort(diff.begin(), diff.end());
            
            int sz = diff.size();

            long long sum=0LL;
            for(int i=0;i<(sz-ladders);++i) sum+=diff[i];
            
            return sum<=bricks;
        };

        int l = 0, r = n-1;
        if(check(r))return r;
        
        while(l+1<r){
            int mid = (l+r)/2;
            if(check(mid)) l=mid;
            else r=mid;
        }
        
        return l;
    }
};