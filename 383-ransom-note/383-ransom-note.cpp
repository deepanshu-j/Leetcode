class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> freq(26, 0);
        
        for(auto &ch: magazine)
            freq[ch - 'a']++;
        
        
        for(char &ch: ransomNote){
            freq[ch-'a']--;
        }
        
        for(int i=0;i<26;++i)
            if(freq[i]<0)return 0;
        return 1;
        
    }
};