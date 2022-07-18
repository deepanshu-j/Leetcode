#pragma GCC optimize("O2")
 
#define rep(i,a,b) for(int i=a;i<b;++i)
using pii = pair<int,int>;
// struct hash_pair {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const
//     {
//         auto hash1 = hash<T1>{}(p.first);
//         auto hash2 = hash<T2>{}(p.second);
 
//         if (hash1 != hash2) {
//             return hash1 ^ hash2;             
//         }
         
//         // If hash1 == hash2, their XOR is zero.
//           return hash1;
//     }
// };
 
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};


class Solution {
public:
    
    
    int func(vector<vector<int>>& a, int target) {
         
        int m = a.size(), n = a[0].size();
        
        int p[m][n];
        memset(p, 0, sizeof p);
        
        rep(i,0,m){
            rep(j,0,n){
                
                p[i][j] += a[i][j];
                if(i-1>=0) p[i][j]+=p[i-1][j];
                if(j-1>=0) p[i][j]+=p[i][j-1];
                if(i-1>=0 and j-1>=0)p[i][j]-=p[i-1][j-1];
                
            }
        }
        
        // rep(i,0,m){
        //     rep(j,0,n){
        //         cout<<p[i][j]<<" ";
        //     }cout<<"\n";   
        // }
        
        
        int ans = 0;
        unordered_map<int, int> mp[101][101];
        
        unordered_map<int, unordered_map<int, int> > mp2, mp3;
        
        rep(i,0,m){
            rep(j,0,n){
                
                
                int cur = p[i][j];
                if(cur==target)++ans;
                ans += mp2[i][cur-target];
                ans += mp3[j][cur-target];
                
                rep(j1, 0, j){
                    int f = cur - target - p[i][j1];
                    // pii pi = make_pair(j1, j);
                    // if(mp.count(pi)>0)
                        ans += mp[j1][j][f];
                }   
                
                mp2[i][p[i][j]]++;
                mp3[j][p[i][j]]++;
            }
            
            rep(j2,0,n){
                rep(j1,0,j2){
                    int val = p[i][j2] - p[i][j1];
                    mp[j1][j2][val]++;
                }
            }
            
        }
        
        
        
        
        return ans;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& a, int target) {
        
        int ans = func(a, target);
        
        return ans;
        
    }
};