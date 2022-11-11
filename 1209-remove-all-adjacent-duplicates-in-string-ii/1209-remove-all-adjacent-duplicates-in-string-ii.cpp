using pii = pair<char,int>;
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pii> stk; // {index, freq}
        
        int n = s.length();
        
        for(int i=0;i<n;){
            
            int j = i;
            
            while(j<n and s[i]==s[j]) ++j;
            
            int cnt = j-i;
            
            int stk_top_cnt = stk.empty() ? 0 : stk.top().second;
            char stk_top_el = stk.empty() ? '0' : stk.top().first;
            
            int tot = cnt;
            if(stk_top_el == s[i]){
                stk.pop();
                tot += stk_top_cnt;
            }
            
            tot %= k;
            if(tot>0){
                stk.push({s[i], tot});
            }
            
            i = j;
        }
        
        string ans = "";
        
        while(!stk.empty()){
            
            int cnt = stk.top().second;
            while(cnt--)
            ans += stk.top().first;
            
            stk.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};