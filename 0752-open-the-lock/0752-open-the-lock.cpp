class Solution {
public:
    
    string inc_idx_k(string s, int k){
        int val = s[k] - '0';
        val++; val%=10;
        s[k] = val + '0';
        return s;
    }
    
    string dec_idx_k(string s, int k){
        int val = s[k] - '0';
        val--; if(val<0) val+=10; val%=10;
        s[k] = val + '0';
        return s;
    }

    int openLock(vector<string>& deadends, string target) {
    
        set<string> bad(deadends.begin(), deadends.end());
        // BFS //
        map<string, int> steps;
        
        string start = "0000";
        
        steps[start] = 0;
        queue<string> q;
        q.push(start);
        
        while(!q.empty()){
            // if(steps.find(start) != steps.end()) 
            string cur = q.front(); q.pop();
            if(bad.count(cur) != 0) continue;
            // cout<<cur<<"\n";
            int cur_steps = steps[cur];
            if(cur == target) return cur_steps;
            for(int k=0;k<4;++k){
                string nxt = inc_idx_k(cur, k);
                string prv = dec_idx_k(cur, k);
                if(steps.find(nxt) == steps.end() and bad.count(nxt) == 0) {
                    steps[nxt] = cur_steps + 1;
                    q.push(nxt);
                } 
                if(steps.find(prv) == steps.end()and bad.count(prv) == 0) {
                    steps[prv] = cur_steps + 1;
                    q.push(prv);
                }
            }            
        }
        return -1;
    }
};