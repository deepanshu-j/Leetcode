class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        
        map<int,int> mp;
        
        int i=0;
        int ans=0;
        for(int j=0;j<n;++j){
            int val=s[j]-'a';
            mp[val]++;
            
            while(mp[val]>1 and i<j){
                // keep removing 
                mp[s[i]-'a']--;
                ++i;
            }
            
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};