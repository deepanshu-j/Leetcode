class Solution {
public:
    
    int fib(int n) {
        if(n<=1)return n;
        int prev = 1, sec_prev = 0;
        
        int cur;
        for(int i=2;i<=n;++i){
            cur = prev + sec_prev;
            sec_prev = prev;
            prev = cur;
        }
        return cur;
    }
};