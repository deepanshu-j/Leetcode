#define vi vector<int> 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int inf = 0x3f3f3f3f;
        sort(a.begin(), a.end(),[](vi &l, vi &r){
            if(l[1]==r[1])return l[0]<r[0];
                return l[1]<r[1];
        });
        
        int n = a.size();
        
        vector<vi> ans;
        
        vi curr = {inf, inf};
        
        for(int i=n-1; i>=0; --i){
            
            if(a[i][1]>=curr[0] and a[i][1]<=curr[1]){
                
                curr[0] = min(curr[0], a[i][0]);
                
            }else{
                ans.push_back(curr);
                curr = a[i];
            }
        }
        if(ans.back()!=curr)ans.push_back(curr);
        
        sort(ans.begin(), ans.end());
        ans.pop_back();
        
        return ans;
    }
};