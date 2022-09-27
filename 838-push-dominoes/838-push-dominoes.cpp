class Solution {
public:
    string res;
    vector<bool> vis;
    void dp(int i, int j, bool left, bool right){
           
            if(left&&right){
                while(i<j){
                    vis[i] = 1;
                    vis[j] = 1;
                    res[i++] = 'R';                
                    res[j--] = 'L';
                }
            }
            else
            if(left){
                while(i<=j){
                    vis[i] = 1;
                    res[i++] = 'R';
                    
                }
            }
            else
            if(right){
                while(i<=j){ 
                    vis[j] = 1;
                    res[j--] = 'L';
                    
                }
            }
        };
        
        
    
    string pushDominoes(string s) {
       
        s = "L" + s + "R";
        res = s;
        int sz = s.length();
        vis.resize(sz, 0);
        
        
        for(int k=0;k<sz;++k){
            
            int i = k, j = k;
            if(vis[i] or s[i]!='.')continue;
            
            while(i>=0 && s[i]=='.')    --i;
            while(i<sz && s[j]=='.')    ++j;
            
            bool left = (i>0 && s[i]=='R')? 1 : 0;
            bool right = (j<sz && s[j]=='L') ? 1 : 0;

            dp(i+1, j-1, left, right);
            
        }
        
        return res.substr(1, sz-2);
    }
};
