class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        vector<int> ans;
        multiset<int> ms;
        
        int zeros = 0;
        for(auto &el: changed){
            if(el == 0) zeros++;
            else
            ms.insert(el);
        }
        
        if(zeros&1)return vector<int>();
        else{
            zeros>>=1;
            while(zeros--)ans.emplace_back(0);
        }
        
        bool ok = 1;
        while(1){
            
            if(ms.empty())break;
            
            int sm = *ms.begin();
            int db = 2*sm;
            if(ms.count(db) == 0){
                ok = 0;
                break;
            }
            
            // remove double //
            ms.erase(ms.find(sm));
            ms.erase(ms.find(db));
            
            ans.emplace_back(sm);
        }
        
        
        if(ok) return ans;
        else return vector<int>();
    }
};