class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        int idx = 0, n = tickets.size();
        while(tickets[k] > 0){
            if(tickets[idx%n] == 0) {
                ++idx; continue;
            }
            tickets[idx%n]--, ++ans;
            ++idx;
        }
        
        return ans;
    }
};