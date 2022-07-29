class Solution {
public:
        
    
    string compute_hash(string &pattern){
        
        string pattern_hash = "";
        
        int hash_val = 'a';
        map<char, char> charSet;
        for(auto &ch: pattern){
            if(charSet.count(ch)==0){
                charSet[ch] = hash_val;
                pattern_hash += hash_val;
                hash_val++;
            }else{
                pattern_hash += charSet[ch];
            }
        }
        
        return pattern_hash;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> matching_words;
        
        string pattern_hash = compute_hash(pattern);
        
        for(auto &w: words){
            if(compute_hash(w) == pattern_hash)
                matching_words.emplace_back(w);
        }
        
        return matching_words;
    }
};