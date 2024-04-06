class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        
        stack<int> stk;
        vector<int> rem;
        for(int i=0;i<s.length();++i){
            char ch = s[i];
            if(ch == '(' or ch == ')'){
                if(ch == ')'){
                    if(stk.empty()){
                        rem.push_back(i);
                    }else {
                        stk.pop();
                    }
                }else{
                    stk.push(i);
                }
            } 
        }
        
        while(!stk.empty()) { rem.push_back(stk.top()); stk.pop(); } 
        
        set<int> st(rem.begin(), rem.end());
        for(int i=0, j=0;i<s.length();++i){
            if(st.count(i)==0) ans += s[i];
        }
        
        return ans;
    }
};