class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        int ans = 1;
        
        int n=words.size();
        unordered_map<string, int> dp;
        
        for(auto &x: words) dp[x] = 1;
        
        sort(words.begin(), words.end(), [](string &left, string &right){
           return (left.length()<right.length()); 
        });
        
        for(int i=n-1;i>=0;--i){
            
            // cout<<words[i]<<"\n";
            int len = words[i].length();
            for(int j=i+1;j<n;++j){
                
                if(words[j].length() != len+1 )continue;
                
                // check if i is predecssor of j //
                bool ok=true;
                
                // 0 1 2 3 //
                // a b c   //
                // a b a c //
                
                // the first place where they differ is 2 after that they are again equal //
                int k;
                for(k = 0; k<len; ++k){
                    if(words[i][k] != words[j][k])break;
                }
                
                if(k<len) ok = (words[i].substr(k) == words[j].substr(k+1));
        
                // if(words[i]=="a"){
                //     cout<<ok<<"\n";
                // }
                
                 // update // 
                if(ok)  dp[words[i]] = max(dp[words[i]], dp[words[j]]+1);   
            }
            
            ans = max(ans, dp[words[i]]);
        }
        
        return ans;
    }
};