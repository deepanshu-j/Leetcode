#define rep(i,a,b) for(int i=a;i<b;++i)
class Solution {
public:
    
    class trie{
        public:
        int index;
        trie* next[26];
        bool complete_word = false;
        
        trie(){
            rep(i,0,26)next[i] = nullptr; 
        }
    };
    
    trie* Trie;
    vector<string> products;
    void insert(string &s, int index){
        int n=s.length();
        
        trie* ptr = Trie;
        
        rep(i,0,n){
            int val = s[i]-'a';
            if(ptr->next[val]==nullptr){
                ptr->next[val] = new trie();
            }
            
            ptr = ptr->next[val];
        }
        
        ptr->complete_word = true;
        ptr->index =  index;
    }
    
    vector<string> find(string &s){
        
        int n=s.length();
        vector<string> res;
        
        trie* ptr = Trie;
        
        rep(i,0,n){
            int val = s[i]-'a';
            if(ptr->next[val]==nullptr){
                return res;
            }
            ptr = ptr->next[val];
        }
        int cnt = 3;
        // now prune from here //
        
        prune(ptr, cnt, res);
        
        return res;
    }
    
    void prune(trie* ptr, int &cnt, vector<string>& res){
        
        if(cnt==0 or !ptr)return;
        
        if(ptr->complete_word){
            --cnt;
            res.push_back(products[ptr->index]);
        }
        
        rep(i,0,26){
            prune(ptr->next[i], cnt, res);
        }
        
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        Solution::products = products;
        Trie = new trie();
        
        rep(i,0,products.size()){
            insert(products[i], i);    
        }
        
        vector<vector<string>> ans;
        string curr="";
        for(char ch: searchWord){
            curr += ch;
            ans.push_back( find(curr) );
        }
    
        return ans;
    }
};