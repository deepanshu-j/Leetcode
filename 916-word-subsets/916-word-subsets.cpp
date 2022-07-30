class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        map<char,int> requirement;
        
        for(auto &word: words2){
            
            map<int, int> mp;
            
            for(auto &ch: word){
                mp[ch]++;
                requirement[ch] = max(requirement[ch], mp[ch]);
            }
            
        }
        
//         for(auto [el, cnt]: requirement){
//             cout<<el<<":"<<cnt<<"\n";
//         }
        
        vector<string> universal_words;
        
        for(string &word: words1){
            
            map<char, int> now;
            
            for(auto &ch: word)
                now[ch]++;
            
            bool ok = true;
            for(auto &[el, cnt]: requirement){
                
                if(now[el]<cnt){
                    ok = false;
                    break;
                }
                
            }
            
            if(ok) universal_words.emplace_back(word);
        }
        
        return universal_words;
    }
};