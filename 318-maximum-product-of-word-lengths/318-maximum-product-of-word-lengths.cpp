class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        vector<vector<bool>> freq;
        freq.reserve(words.size());
        for(int i=0;i<words.size();++i){
            
            vector<bool> mp(26);
            
            for(int j=0;j<words[i].length();++j){
                if(mp[words[i][j]-'a']==0)
                    mp[words[i][j]-'a']=1;
            }
            
            freq.emplace_back(mp);
            
        }
        
        
        int ans=0;
        for(int i=0;i<words.size();++i){
            for(int j=i+1;j<words.size();++j){
                
                int len = words[i].length() * words[j].length();
                
                if(len<=ans)continue;
                
                bool ok=1;
                
                for(int c=0;c<26;++c)
                    if(freq[i][c] or freq[j][c])
                        if(freq[i][c]==freq[j][c])
                            ok=0;
                
                if(ok){
                    
                    ans = max(ans, len);
                
                }
                
            }
        }
        return ans;
    }
};