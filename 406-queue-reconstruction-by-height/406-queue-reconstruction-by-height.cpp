class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> ans(n);
        
        sort(a.begin(), a.end());
        // for(auto x: a)cout<<"["<<x[0]<<","<<x[1]<<"]"<<"  ";
        
        vector<bool> done(n, 0);
        for(int i=0;i<n;++i){
            int idx = a[i][1];
            int cur = 0;
            int j = 0;
            for( ; j < n ; ++j){
                if(ans[j].size()==2){
                    if(ans[j][0]>=a[i][0]){
                        ++cur;
                    }
                    continue;
                }
                
                if(cur==idx){
                    done[j] = 1;
                    ans[j] = a[i];
                    break;
                }
                ++cur;
            }
            
        }
        
        return ans;
    }
};