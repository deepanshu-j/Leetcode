
class Solution {
public:
    
    set<long long> mp;
    
    long long compute_hash(string const& s) {
        const int p = 31;
        const int m = 1e9 + 9;
        long long hash_value = 0;
        long long p_pow = 1;
        for (char c : s) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }

    void add_hashes(string &s){
        const int p = 31;
        const int m = 1e9 + 9;
        long long hash_value = 0;
        long long p_pow = 1;
        for (char c : s) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            mp.insert(hash_value);
            p_pow = (p_pow * p) % m;
        }
    }
    
    int minimumLengthEncoding(vector<string>& words) {
       sort(words.begin(), words.end(), [](string &l, string &r){
           return l.length() > r.length();
       }); 
        
        int cnt = 0, i = 0;
        vector<int> idx;
        for(auto &s: words){
            
            reverse(s.begin(), s.end());
            
            if(mp.count(compute_hash(s)) > 0 ){
                continue;
            }
            
            add_hashes(s);
            ++cnt;
            idx.push_back(i);
            ++i;
        }
        
        int ans = cnt;
        for(auto x: idx){
            ans += words[x].length();
        }
        return ans;
    }
};