class Solution {
public:
    int n;
    vector<int> a;
    int memo[1001][2];
    int dp(int i, bool need_pos){
        if(i>=n)return 0;
        int ans = 0;
        for(int j=i+1;j<n;++j){
            
            if(memo[i][need_pos]!=-1)return memo[i][need_pos];
            
            if(need_pos){
                if(a[i]-a[j]>0){
                    ans = max(ans, 1+dp(j, !need_pos));
                }
            }else{
                if(a[i]-a[j]<0){
                    ans = max(ans, 1+dp(j, !need_pos));
                }
            }
        }
        return memo[i][need_pos] = ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        a = nums;
        n = nums.size();
        
        memset(memo, -1, sizeof memo);
        
        return 1+max(dp(0, 0), dp(0, 1));
    }
};