class Solution {
public:
    unsigned long long getFirstSetBitPos(long long n)
    {
        return log2(n & -n) + 1LL;
    }
    bool isPowerOfFour(int n) {
        
        int cnt = __builtin_popcountll(n);
        if(cnt == 1){
            int setBitPos = getFirstSetBitPos(n);
            return setBitPos&1;
        }
        else return 0;
        
    }
};