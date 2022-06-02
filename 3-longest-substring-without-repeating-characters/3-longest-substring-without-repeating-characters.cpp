class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        
        map<int,int> mp;
        int j=0;
        int ans=0;
        for(int i=0;i<n;++i){
            int val = s[i]-'a';
            mp[val]++;
            
            while(mp[val]>1){
                int val_j = s[j]-'a';
                mp[val_j]--;
                j++;
            }
            
            ans = max(ans, i-j+1);
        }
        
        return ans;
    }
};