#define pii pair<long long, long long> 
class WordFilter {
public:
    
    map<pii, int> mp;
    
    void compute_hash(string s, int index) {
        const int p = 31;
        const int m = 1e9 + 9;
        long long hash_value = 0;
        long long p_pow = 1;
        vector<long long> pre, suf;
        for (char c : s) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            // hash value of prefix //
            pre.push_back(hash_value);
            p_pow = (p_pow * p) % m;
        }
        
        reverse(s.begin(), s.end());

        hash_value = 0;
        p_pow = 1;
        for (char c : s) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            // hash value of suffix //
            suf.push_back(hash_value);
            p_pow = (p_pow * p) % m;
        }
        
        for(auto x: pre){
            for(auto y: suf){
                mp[{x, y}] = index;
            }
        }
        
    }
    
    WordFilter(vector<string>& words) {
        
        for(int i=0;i<words.size();++i){
            compute_hash(words[i], i);
        }

    }
    
    long long compute_string_hash(string const& s) {
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
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        long long st = compute_string_hash(prefix), 
            end = compute_string_hash(suffix);
        
        if(mp.count({st, end}) > 0){
            return mp[{st, end}];
        }else return -1;
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */