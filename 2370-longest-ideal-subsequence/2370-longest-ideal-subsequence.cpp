class Solution {
public:
    int longestIdealString(string s, int k) {
        
        vector<int> end(26, 0); // best length ending at 'a', 'b' so on 
        // stores a pe end hone wale kitne , b pe end hone wale kitne ..
        int n = s.size();
        // for(auto ch: s) end[ch-'a'] = 1;
        
        vector<int> ans(n, 1);
        end[s[0]-'a'] = 1;
        ans[0] = 1;
        
        for(int i=1;i<n;++i){
            int best = -1;
            int ch = s[i] - 'a';
            for(int j=0;j<26;++j){
                if(abs(ch-j) <= k){
                    best = max(best, end[j]);
                } 
            }
            if(best == -1){
                end[ch] = max(end[ch], 1);
            }else end[ch] = max(end[ch], best+1);

        }
        
        return *max_element(end.begin(),end.end());
    }
};