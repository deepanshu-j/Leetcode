// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool good(int A[], int N, int M, int x){
    
        int cnt = 0;
        
        int cur = 0;
        for(int i=0;i<N;++i){
            if(A[i]>x)return 0;
            
            cur += A[i];
            
            if(cur>x){
                // start a new one //
                cur = A[i];
                ++cnt;
            }
        }
        if(cur>x)++cnt;
        
        // cout<<"cnt: "<<cnt<<"\n";
        return (cnt<M);
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        
        
        int mx = 0;
        for(int i=0;i<N;++i) mx+=A[i];
        
        int l = -1, r = mx; 
        
        int mid;
        
        while(l<r-1){
            mid = (l+r)/2;
            bool g=good(A, N, M, mid);
            
            if(g){
                r = mid; 
            }else l = mid;
            
        }
        
        // if(mid==-1)return 0;
        // if(mid==mx)return mx;
        return l+1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends