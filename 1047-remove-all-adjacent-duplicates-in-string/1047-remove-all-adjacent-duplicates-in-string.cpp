class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        
        stack<int> stk;
        
        for(int i=0;i<n;++i){
            
            if(stk.empty()){
                stk.push(i);
                continue;
            }
            
            if(s[stk.top()] == s[i]) stk.pop();
            else stk.push(i);
        }
        
        string ans = "";
        while(!stk.empty()){ 
            ans += s[stk.top()]; stk.pop();
        }
        
        reverse(ans.begin(), ans.end())
        ;return ans;
    }
};