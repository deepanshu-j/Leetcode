class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int mx=prices[n-1];
        
        stack<int> min_stk;
        int mn=prices[0];
        for(int i=0;i<n-2;++i){
            mn=min(mn, prices[i]);
            min_stk.push(mn);
        }
        
        int res=0;
        int prev_p2=0;
        for(int i=n-1;i>0;--i){
            // consider i as the mn and you have the further arr's max
            int p2=0;
            // if(i<n-1)
            p2 = max({p2, prev_p2, mx-prices[i] });
            
            prev_p2= p2;
            mx = max(mx, prices[i]);
            
            int p1=0;
            if(!min_stk.empty()){
                p1=max(p1, prices[i-1]-min_stk.top());
                min_stk.pop();
            }
            
            res=max(res, p1+p2);
        }
        
        if(prices[0]<prices[n-1])
        res = max(res, prices[n-1]-prices[0]);
        
        return res;
    }
};