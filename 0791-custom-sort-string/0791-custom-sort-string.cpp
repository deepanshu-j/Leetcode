class Solution {
public:
    string customSortString(string order, string s) {
        
        
        string res = "";
        multiset<char> s1, s2;
        for(auto ch : order) s1.insert(ch);
        for(auto ch : s) s2.insert(ch);
        
        for(auto ch: order){
            
            int cnt = s2.count(ch);
            if(cnt>0) {
                while(cnt--) res += ch;
            }
        }
        
        
        for(auto ch: s){
            if(s1.count(ch) == 0) res += ch;
        }
        return res;
    }
    
};