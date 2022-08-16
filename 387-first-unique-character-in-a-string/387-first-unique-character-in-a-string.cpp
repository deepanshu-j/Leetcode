class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26] = {0};
        int index[26] = {-1};
        
        int n= s.length();
        for(int i=0;i<n;++i){
            cnt[s[i] - 'a']++;
            index[s[i] - 'a'] = i;
        }
        
        int ans = 1e6;
        for(int i=25;i>=0;--i){
            
            if(cnt[i] == 1){
                if(ans > index[i]) ans = index[i];
            }
            
        }
        if(ans == 1e6)return -1;
        return ans;
    }
};