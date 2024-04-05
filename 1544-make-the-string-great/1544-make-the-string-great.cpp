class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for(auto ch: s){
            if(stk.empty()){
                stk.push(ch);
            }else{
                if(abs(stk.top() - ch) == 32){
                    stk.pop();
                }else stk.push(ch);
            }
        }
        
        string ans = "";
        while(!stk.empty()) ans += stk.top(), stk.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};