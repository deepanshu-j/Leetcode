class Solution {
public:
    
    vector<int> multiply(vector<int> left, vector<int> right, char oper){
        vector<int> ans;
        for(auto x: left){
            for(auto y: right){
                
                if(oper =='-' )
                    ans.emplace_back(x-y);
                else
                if(oper == '+')
                    ans.emplace_back(x+y);
                else
                if(oper == '*' )
                    ans.emplace_back(x*y);
                
            }
        }
        
        return ans;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        string s=expression;
        int n=expression.length();
        vector<int> ans;
        if(n<=2){
            int val = stoi(expression);
            
            ans.emplace_back(val);
            return ans;
        }
      
        for(int i=0;i<n;++i){
            if(s[i]=='-' or s[i]=='*' or s[i]=='+'){
                vector<int> left = diffWaysToCompute(s.substr(0, i))
                    , right=diffWaysToCompute(s.substr(i+1));
                
                for(auto x: multiply(left, right, s[i]))
                    ans.emplace_back(x);
            }
        }
        return ans;
    }
};