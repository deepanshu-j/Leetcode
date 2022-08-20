class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        
        // sort(stations.begin(), stations.end());
        
        int n = stations.size();
        if(startFuel >= target)return 0;
        
        int cur = startFuel;
        
        int ans = 0;
        int i = 0;  
        
        while(cur<target){
            
            while( i<n and cur >= stations[i][0] ){
                pq.push(stations[i][1]);
                ++i;
            }
            
            if(cur>=target)break;
            if(pq.empty()) return -1;
    
            // if(pq.size()>0){
                cur += pq.top();
                ++ans;
                pq.pop();
            // }
        
            
        }
    
        if(cur>=target)return ans;
        
        return -1;
        return ans;
    }
};