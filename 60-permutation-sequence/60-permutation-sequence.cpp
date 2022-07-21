#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define debugvec(x) cout<<#x<<": [ ";\
        for(int iii=0;iii<x.size();++iii)\
        if(iii<x.size()-1)cout<<x[iii]<<" ,";else cout<<x[iii];\
        cout<<" ]\n";
class Solution {
public:
    
    string ans="";
    int fact[20];
    void pre(){
        
        fact[0] = 1;
        for(int i=1; i<10; ++i){
            fact[i] = fact[i-1]*i;
        }
        
    }
    
    void recc(vector<int> &s, int k ){
        
        int n = s.size();
        
        // if(n==0 and k>0)cout<<"Fish\n";
        if(n==0)return;
        
        int idx = k/fact[n-1];
        
        // debug(idx)
        // debug(k)
        // debugvec(s)
        
        ans += to_string(s[idx]);
        
        s.erase(s.begin()+idx);
        
        recc( s,  k-(fact[n-1]*idx) );
    }
    
    string getPermutation(int n, int k) {
        
        pre();
        
        vector<int> s;
        for(int i=1;i<=n;++i)s.emplace_back(i);
        
        recc(s, k-1);
        
        return ans;
    }
};