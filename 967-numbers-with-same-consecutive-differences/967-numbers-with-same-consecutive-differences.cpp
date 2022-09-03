class Solution {
public:
    
    vector<string> ans;
    
    string cur = "";
    int nn;
    
    void dfs(int n, int prev, int &k){
        
        if(n == 0){
            ans.push_back(cur);
            return;
        }
        
        
        int i;
        
        if(n == nn){
            
            for( int i = 1; i<10; ++i){                  
                cur += ('0'+i);
                dfs(n-1, i, k);
                cur.pop_back();
            }
            
        }
        else 
        for( int i = 0; i<10; ++i){
            if(abs(i-prev) == k){  
                cur += '0'+i;
                dfs(n-1, i, k);
                cur.pop_back();
            }
        }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        this->nn = n;
        dfs(n, -1, k);
        
        vector<int> res;
        for(auto &x: ans){
            res.push_back(stoi(x));
        }
        
        return res;
    }
};