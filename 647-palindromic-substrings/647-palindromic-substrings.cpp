#define vi vector<int>
#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vi oc(n+1);
        
        auto check = [&n](int x)->bool{
              return (x>=0 and x<n);
        };
        
        int ans=0;
        rep(i,0,n){
            oc[i]=1;
            int len=1;
            while(check(i-len) && check(i+len) && s[i-len]==s[i+len]){
                oc[i]++;
                len++;
            }
            
            ans+=oc[i];
        }
        
        
        rep(i,1,n){
            int cnt=0;
            int len=0;
            while(check(i-1-len) && check(i+len) && s[i-1-len]==s[i+len]){
                ++len;
                ++cnt;
            }
            ans+=cnt;
        }
        
        return ans;
    }
};