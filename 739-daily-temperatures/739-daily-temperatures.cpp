class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> next_greater_element(n, 0);
        
        stack<int> stk;
        
        for(int i = n-1; i>=0; --i){
            
            int temp = temperatures[i];
            
            while(!stk.empty() and temperatures[stk.top()] <= temp){
                stk.pop();
            }
            
            int cur_ans = stk.empty() ? -1 : stk.top(); 
            next_greater_element[i] = cur_ans;
            stk.push(i);    
        }
        
        vector<int> ans(n, 0);
        
        for(int i=0;i<n;++i){
            if(next_greater_element[i] !=-1)
            ans[i] = next_greater_element[i] - i; 
        }
        
        return ans;
    }
};