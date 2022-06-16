class Solution {
public:
    string longestPalindrome(string s) {
        
        // expansion center //
        
        int n = s.length();
        
        int st=0,end=0;
        int mx=1;
        
        for(int i=0; i<n; ++i){
            int len=1;
            while(i-len>=0 and i+len<n and s[i-len]==s[i+len]){
                if(i+len-(i-len)+1 > mx ){
                    st = i-len;
                    end = i+len;
                    mx = i+len-(i-len)+1;
                }
                ++len;
            }
        }
        
        for(int i=0; i<n; ++i){
            int len=0;
            while(i-len>=0 and i+1+len<n and s[i-len]==s[i+1+len]){
                if(i+1+len-(i-len)+1 > mx ){
                    st = i-len;
                    end = i+1+len;
                    mx = i+1+len-(i-len)+1;
                }
                ++len;
            }
        }
        
        string ans="";
        for(int i=st;i<=end;++i)ans += s[i];
        
        return ans;
    }
};