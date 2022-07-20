class Solution {
public:
    
    /*
 s="   a    b   c   d   e "
 
 a    -1   -1  -1
 b     1   -1  -1
 c     2    2  -1
 .
 .
 .
 z    -1   -1
    
    
    */
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n = s.length();
        s = "_" + s;
        vector<vector<int>> nxt(n+1, vector<int>(26, -1));
        
        // form the data structure //
        for(int i=n-1; i>=0; --i){
            // moving backwards //
            if(i+1<=n){
                // copy the prev one //
                nxt[i] = nxt[i+1];
            }
            
            nxt[i][s[i+1]-'a'] = i+1;
        }
        
        // cout<<"TABLE:\n";
        // for(int j=0;j<26;++j){
        //     for(int i=0;i<=n;++i){
        //         cout<<nxt[i][j]<<" ";   
        //     }
        //     cout<<"\n";
        // }
        
        // nxt[0][s[1]-'a'] = 1; 
        
        int cnt = 0;
        for(auto &w: words){
            
            int idx = 0;
            bool ok = 1;
            for(auto &ch: w){
                if(nxt[idx][ch-'a']!=-1){
                    idx = nxt[idx][ch-'a'];
                }else{
                    ok=0;
                    break;
                }
            }    
            if(ok)++cnt;
        }
        
        return cnt;
    }
};