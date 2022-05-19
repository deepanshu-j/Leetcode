#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
class Solution {
public:
    
    vector<vector<int>> dist, a;
    int n,m, mx=1;
    
    bool inside(int i, int j){
        return (i>=0 and j>=0 and i<m and j<n); 
    }
    
    int recc(int i, int j){
        
        if(dist[i][j]>1)return dist[i][j];
        
        int ans=0;
        if(inside(i-1, j) and a[i-1][j]>a[i][j]){
            ans = max(ans, recc(i-1, j));
        }
        
        if(inside(i+1, j) and a[i+1][j]>a[i][j]){
            ans = max(ans, recc(i+1, j));
        }
        
        if(inside(i, j-1) and a[i][j-1]>a[i][j]){
            ans = max(ans, recc(i, j-1));
            
        }
        
        if(inside(i, j+1) and a[i][j+1]>a[i][j]){
            ans = max(ans, recc(i, j+1));   
        }
        return dist[i][j] = 1+ans;
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        a=matrix;
        m=matrix.size();
        n=matrix[0].size();
        dist.resize(m, vector<int>(n, -1) );
        // rep(i,0,m)rep(j,0,n)dist[i][j]=-1;
        
        rep(i,0,m){
            rep(j,0,n){
                if(dist[i][j]==-1){
                    mx=max(mx, recc(i, j));
                }
                mx=max(mx, dist[i][j]);
            }
        }
        // rep(i,0,m){
        //     rep(j,0,n){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return mx;    
    }
};