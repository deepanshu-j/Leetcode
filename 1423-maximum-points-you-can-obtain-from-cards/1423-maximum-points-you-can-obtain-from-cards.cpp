class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        long long tot =  accumulate(a.begin(), a.end(), 0LL);
        
        int n = a.size();
        // window of size = n-k
        
        int window = 0;
        int sz = n-k;
        for(int i=0;i<sz;++i){
            window += a[i];
        }
        
        int mn = window;
        
        for(int i=sz;i<n;++i){
            window += a[i];
            window -= a[i-sz];
            mn = min(mn, window);
        }
        
        return (tot-mn);
        
    }
};