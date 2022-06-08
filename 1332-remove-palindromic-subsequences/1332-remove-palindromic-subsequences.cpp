class Solution {
public:
    bool ispalin(string s){
        int n=s.length();
        
        for(int i=0;i<n;++i){
            if(s[i]!=s[n-1-i])return 0;
        }
        return 1;
    }
    
    int removePalindromeSub(string s) {
        int n=s.length();
        if(n==0)return 0;
        
        return (ispalin(s)?1:2);
    }
};