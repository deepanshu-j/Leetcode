class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0, j = n-1;

        while(i<j){
            if(s[i] != s[j]) return j-i+1;
            char ch = s[i];
            while(i<n and s[i] == ch)++i;
            while(j>=0 and s[j] == ch)--j;
        }
        
        if(i<=j) return j - i + 1;
        return 0;
    }
};