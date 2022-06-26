class Solution {
public:
    string s;
    int n;
    
    bool ispalin(string &s){
        int n = s.size();
        for(int i=0;i<n;++i){
            if(i<n-i-1 and s[i]!=s[n-i-1])return 0;    
        }
        return 1;
    }
    
    vector<vector<string>> dp(int i){
        
        vector<vector<string>> ans;
        
        string p = "";
        for(int j=i;j<n;++j){
            p+=s[j];
            if(ispalin(p)){
                if(j+1<n){
                    vector<vector<string>> next = dp(j+1);
                    for(auto x: next){
                        vector<string> sub;
                        sub.emplace_back(p);
                        sub.insert( sub.end(), x.begin(), x.end() );
                        ans.emplace_back(sub);
                    }
                }else{ 
                    vector<string> sub;
                    sub.emplace_back(p);
                    ans.emplace_back(sub);
                }
            }
        }
        return ans;
    }
    
    vector<vector<string>> partition(string s) {
        Solution::s = s;
        n = s.size();
        
        return dp(0);
    }
};