class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        deque<int> dq;
        int i=0, cnt = 0;
        int n = tokens.size();
    
        if(n == 0)return 0;
        
        sort(tokens.begin(), tokens.end());
        
        i=0;
        for(;i<n;++i){
            if(power >= tokens[i]){
                power -= tokens[i];
                ++cnt;
            }else break;
        }
        
        while(i<n){
            dq.push_back(tokens[i]);
            ++i;
        }
        
        // i = 0, j = dq.size()-1;
        while(dq.size()){
            
            if(cnt==0)break;
            
            int cur_score = 0;
            int cur_power = power+dq.back();
            dq.pop_back();
            cur_score--;
            
            while(dq.size()){
                if(cur_power >= dq.front()){
                    
                    cur_power -= dq.front();
                    dq.pop_front();
                    
                    ++cur_score;
                    
                }else break;
            }
            
            if(cur_score<0) break;
            cnt += cur_score;
            power = cur_power; 
        }
        
        while(dq.size()>0 and power >= dq.front()){
            ++cnt;
            power -= dq.front();
            dq.pop_front();
        }
        
        return cnt;
    }
};