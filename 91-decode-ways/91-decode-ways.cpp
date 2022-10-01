class Solution {
public:
    unordered_set<string> us;
    string s;
    int g_ans=-1;
    int memo[110];
    int f(int n){
        if(n==s.length())
            return 1;
        if(n==s.length()+1)
            return 0;
        
        if(memo[n]!=-1)
            return memo[n];
        
        int ans=-1;
        if(s.length()-n>=0 && us.find(s.substr(n,2))!=us.end() ){
            ans=f(n+2)+f(n+1);
        }
        else
        if(us.find(s.substr(n,1))!=us.end())
            ans= f(n+1);
        else
            ans= 0;
        
        return memo[n]=ans;
        
    }
    int numDecodings(string ss) {
        s=ss;
        for(int i=1;i<27;++i){
            us.insert(to_string(i));
        }
        
        memset(memo, -1 , sizeof memo);
        
        if(g_ans!=-1)
            return 0;
        return f(0);
    }
};