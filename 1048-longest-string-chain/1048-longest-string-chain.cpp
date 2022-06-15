class Solution {
    
    bool check(string &a, string &b) {
        
        int len = a.size();
        // 0 1 2 3 //
        // a b c   //
        // a b a c //

        // the first place where they differ is 2 after that they are again equal //
        int k;
        for(k = 0; k<len; ++k){
            if(a[k] != b[k])
                break;
        }

        return (k == len) || ((k<len) && (a.substr(k) == b.substr(k+1)));
    }
    
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string &left, string &right){
           return (left.length()<right.length()); 
        });
        vector<int> dp(n, 1);
        for(int i=n-1;i>=0;--i){
            
            int len = words[i].length();
            for(int j=i+1;j<n;++j){
                if(words[j].length() == len )
                    continue;
                if(words[j].length() > len+1 )
                    break;
                if(check(words[i], words[j]))
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            
        }
        return *max_element(dp.begin(), dp.end());
    }
};