class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int mx = 0, last = 0;
        for(char ch: tasks) freq[ch-'A']++;
        for (int i=0;i<26;i++) 
            mx = max(mx, freq[i]);
        for(auto x: freq) if(x == mx) last++;
        return max((int)tasks.size(), (mx-1)*(n+1) + last);
    }
};