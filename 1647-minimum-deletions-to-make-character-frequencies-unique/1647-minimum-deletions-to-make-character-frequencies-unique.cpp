class Solution {
public:
    int minDeletions(string s) {
        // iterate fom the highest frequency // if its unqiue good, ese
        // try to 
        // 27, 26, 24, 25
        
        map<int, int> mp;
        for(auto ch: s)mp[ch-'a']++;
        multiset<int> freq;
        for(auto x: mp){
            freq.insert(x.second);
        }
        
        // cout<<"freq set\n";
        // for(auto x: freq)cout<<x<<" ";
        // cout<<"\n";
        int ans = 0;
        for(int i=0;i<26;++i){
            
            if(freq.count(mp[i])>1){ // ek se zyada // toh isse hatana chalu karo
                int now = mp[i];
                int del = 0;
                // delete some char //
                
                while(freq.count(mp[i])>0){
                    mp[i]--;
                    del++;
                }
                
                ans += del;
                
                freq.erase(freq.find(now));
                if(mp[i]>0)
                freq.insert(mp[i]);
                
                // cout<<"freq set\n";
                // for(auto x: freq)cout<<x<<" ";
                // cout<<"\n";
            }
            
            
        }
       return ans;
    }
};