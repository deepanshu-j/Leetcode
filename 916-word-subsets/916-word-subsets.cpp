class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        int requirement[26] = {0};
        
        for(auto &word: words2){
            
            int mp[26] = {0};
            
            for(auto &ch: word){
                mp[ch-'a']++;
                requirement[ch-'a'] = max(requirement[ch-'a'], mp[ch-'a']);
            }
            
        }
        
//         for(auto [el, cnt]: requirement){
//             cout<<el<<":"<<cnt<<"\n";
//         }
        
        vector<string> universal_words;
        
        for(string &word: words1){
            
            int now[26] = {0};
            
            for(auto &ch: word)
                now[ch-'a']++;
            
            bool ok = true;
            for(int i=0;i<26;++i){
                
                if(now[i]<requirement[i]){
                    ok = false;
                    break;
                }
                
            }
            
            if(ok) universal_words.emplace_back(word);
        }
        
        return universal_words;
    }
};