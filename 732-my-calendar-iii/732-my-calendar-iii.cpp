class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
       
        mp[start] += 1;
        mp[end] -= 1;
        int ans = 0;
        int pref = 0;
        
        for(auto it : mp) {
            pref += it.second;
            ans = max(ans, pref);
        }
        
        return ans;
        
    }
};