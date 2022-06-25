class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        
        vector<int> b;
        b.emplace_back(-1e6);
        for(auto x: a)b.emplace_back(x);
        b.emplace_back(1e6);
        a = b;
        
        int n = a.size();
        bool ans = 0;
        bool found_bad = 0;
        int mn = a[0], mn2 = -1e6;
        
        bool ans_first = 1;
        for(int i=0;i<n-1;++i){
            
            if(mn<=a[i] and a[i]<=a[i+1]){
                ;
            }
            else{
                if(found_bad){
                    // cout<<"i:"<<i<<"\n";
                    // return false;
                    ans_first = 0;
                }
                found_bad = 1;
                // dont update mn in this one //
                continue;
            }
            mn = max(mn, a[i]);
        }
        
        bool ans_second = 1;
        
        reverse(a.begin(), a.end());
        for(auto &x: a)x*=-1;
        
        // for(auto x: a)cout<<x<<" ";
        
        found_bad = 0;
        mn = -1e6;
        for(int i=0;i<n-1;++i){
            
            if(mn<=a[i] and a[i]<=a[i+1]){
                ;
            }
            else{
                if(found_bad){
                    // cout<<"i:"<<i<<"\n";
                    // return false;
                    ans_second = 0;
                }
                found_bad = 1;
                // dont update mn in this one //
                continue;
            }
            mn = max(mn, a[i]);
        }
        
        
        return ans_first or ans_second;
    }
};
// [3,5,1,6,7]