class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int oneCount = 0;
        for(auto ch: s) if(ch == '1') ++oneCount;
        
        int n = s.length();
        s[n-1] = '1';
        int zeroCount = n - oneCount;
        oneCount --;
        
        for(int i=0;i<oneCount;++i){
            s[i] = '1';
        }
        
        for(int i=oneCount; i<oneCount+zeroCount;++i ){
            s[i] = '0';
        }
        return s;
    }
};