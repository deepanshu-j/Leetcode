class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.reserve(numRows);
        
        for(int i=1;i<=numRows;++i){
            
            vector<int> cur;
            cur.emplace_back(1);
            
            if(ans.size()>0)
            for(int j=0;j<ans.back().size()-1;++j){
                cur.emplace_back(ans.back()[j] + ans.back()[j+1]);
            }
            
            if(i>1)cur.emplace_back(1);
            
            ans.emplace_back(cur);
        }
        
        return ans;
    }
};