class Solution {
public:
    int minPartitions(string n) {
        int mx = -1;
        for(char ch:n){
            mx = max(mx, (ch-'0'));
        }
        
        return mx;
    }
};