//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        vector<int> fact(n+1);
        fact[0] = 1;
        for(int i=1; i<=n; ++i) fact[i] = i * fact[i-1];
        
        /**
            
            1 2 3 4
            1 2 4 3
            1 3 2 4
            1 3 4 2 
            1 4 2 3 = 5/(3!) = 0 -> 1 
            1 4 3 2
            2 1 3 4 = 7/(3!) = 1 -> 2
        
        */
        
        string ans = "";
        set<int> s; 
        for(int i=1;i<=n;++i) s.insert(i);
        
        k--;
        
        while(n>0){
            
            if(n == 1){
                ans += to_string(*s.begin());
                break;
            }
            
            int num = 0, i = 0;
            
            
            // largest multiple of (n-1)! that we can have in k //
            
            // 1 1...1*(n-1)!
            // 2 (n-1)!+1 ... 2*(n-1)!
            // .
            // .
            // n (n-1)(n-1)!+1 ... n*(n-1)!
            
            int coeff = k / fact[n-1];
            
            for(auto x: s){
                if(i == coeff){ num = x; break; }
                ++i;
            }
            
            ans += to_string(num);
            
            s.erase(num);
            k %= fact[n-1];
            n--;

        }
        //  for(auto x: s) ans += to_string(x);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends