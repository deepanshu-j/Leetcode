#define all(x) begin(x),end(x)
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        const int MOD = 1e9 + 7;
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        verticalCuts.insert(verticalCuts.begin(), 0);
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        vector<int> diff_h, diff_v;
        
        sort(all(horizontalCuts));
        sort(all(verticalCuts));
        
        for(int i=1;i<horizontalCuts.size();++i){
            diff_h.emplace_back(horizontalCuts[i]-horizontalCuts[i-1]);
        }
        
        for(int i=1;i<verticalCuts.size();++i){
            diff_v.emplace_back(verticalCuts[i]-verticalCuts[i-1]);
        }
        
        sort(all(diff_h));
        sort(all(diff_v));
        
        int res = ( 1LL* diff_h.back()%MOD * diff_v.back()%MOD )%MOD;
        return res;   
    }
};