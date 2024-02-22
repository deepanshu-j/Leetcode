class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> followers(n+1, 0);
        vector<int> followee(n+1, 0);
        
        for(auto t: trust){
            int a = t[0], b = t[1];
            followee[a]++;
            followers[b]++;
        }
        
        int ans = -1;
        int foundCount = 0;
        for(int i=1;i<=n;++i){
            if(followers[i] == n-1 and followee[i] == 0){
                ans = i;
                foundCount++;
            }
        }
        
        if(foundCount!=1)
            return -1;
        return ans;
    }
};