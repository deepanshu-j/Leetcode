#define ff first
#define ss second
class Solution {
public:
    int cnt(string &s){
        int ans=0;
        for(int i=0;i<s.length();++i)if(s[i]==' ')++ans;
        return ans+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        map<string, int> mp;
        
        for(int i=0;i<messages.size();++i){
            mp[senders[i]] += cnt(messages[i]); 
        }
        
        int mx=-1;
        for(auto &x: mp)mx = max(mx, x.second);
        
//         for(auto x: mp){
//             cout<<x.ff<<" "<<x.ss<<"\n";
//         }
        
        vector<string> res;
        
        for(auto &x: mp)if(x.second == mx)res.emplace_back(x.first);
        
        sort(begin(res), end(res));
        
        return res.back();
    }
};