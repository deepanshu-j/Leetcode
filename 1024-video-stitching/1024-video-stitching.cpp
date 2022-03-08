#define inf 0x3f3f3f3f
class Solution {
public:
    vector<vector<int>> clips;
    int memo[101][101];
    int dp(int time, int n){
        
        if(n==-1){
            if(time==0)return 0;
            else return inf;
        }
        
        if(memo[time][n]!=-1)return memo[time][n];
        int ans=inf;
        vector<int> clip=clips[n];
        if(clip[1]>=time){ // i can pick it //
            ans=min(ans, 1+dp(clip[0], n-1));
        }
        
        ans=min(ans, dp(time, n-1));
        
        return memo[time][n]=ans;
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        
        memset(memo, -1, sizeof memo);
        sort(clips.begin(), clips.end(), [](vector<int> &left, vector<int>& right){
            
            if(left[0]==right[0])return left[1]<right[1];
            
            return left[0]<right[0];
        });
        
        Solution::clips=clips;
        int n=clips.size();
        int res=dp(time, n-1);
        
        if(res==inf)return -1;
        else return res;
    }
};