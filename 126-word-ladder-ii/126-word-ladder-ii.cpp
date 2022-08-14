#define pb push_back
#define eb emplace_back
class Solution {
public:
    string beginWord;
    bool is_adj(string s1, string s2){
        
        int diff = 0;
        int n = s1.length();
        for(int i=0; i<n ; ++i){
            if(s1[i] != s2[i]) ++diff;
        }
        return diff==1;
    }
    
    unordered_map<string, vector<string>> graph;
    unordered_map<string, vector<vector<string>> > memo; 
    
    vector<vector<string>> dfs(string endWord){
        
        int cur_dist = dist[endWord];
        
        if(endWord == beginWord){
            
            vector<vector<string>> ans;
            vector<string> sub{beginWord};
            ans.pb(sub);
            
            return ans;            
        }
        
        if(memo.count(endWord) > 0)return memo[endWord];
        
        vector<vector<string>> ans;
               
        
        for(auto adj: graph[endWord]){
            
            if( dist[adj] == cur_dist-1 ){
                auto sub_ans = dfs(adj);
                
                for(auto &x: sub_ans){
                    x.pb(endWord);
                    ans.pb(x);
                }
               
            }    
            
        }
        
        return memo[endWord] = ans;
        
    }
    
    
    unordered_map<string, int> dist;
    unordered_map<string, bool> seen;
    
    void bfs(string word){
        
        int cur_dist = 0;
        
        queue<string> q;
        q.push(word);
        seen[word] = 1;
        dist[word] = 0;
        
        while(!q.empty()){
            
            auto fr = q.front();    
            q.pop();
            
            for(auto adj: graph[fr]){
                
                if(seen.count(adj) > 0 ) continue;
                
                dist[adj] = 1 + dist[fr];
                
                seen[adj] = 1;
                q.push(adj);
            }
        }
        
    }
    
    vector<vector<string>> uni(vector<vector<string>> v){
        
        set<vector<string>> s;
        vector<vector<string>> ans;
        
        for(auto x: v)s.insert(x);
        
        for(auto x: s)ans.eb(x);
        return ans;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        this->beginWord = beginWord;
        wordList.pb(beginWord);
        
        int sz = wordList.size();
        for(int i=0;i<sz;++i){
            for(int j=i+1;j<sz;++j){
                if( is_adj(wordList[i], wordList[j]) ){
                    graph[wordList[i]].emplace_back(wordList[j]);
                    graph[wordList[j]].emplace_back(wordList[i]);
                }
            }
        }   
        
        
        
        // for(auto key: graph){
        //     cout<<"key:"<<key.first<<"\n";
        //     for(auto ch: key.second) cout<<ch<<' ';
        //     cout<<"\n";
        // }
        
        
        bfs(beginWord);
        // for(auto w: wordList) cout<<w<<" : "<<dist[w]<<" ";
        
        
        auto ans = dfs(endWord);
                
        auto res = uni(ans);
        
        return res;
    }
};