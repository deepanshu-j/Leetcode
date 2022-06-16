#define eb emplace_back
class Solution {
public:
    int n, k, ans;
    vector<int> partitions, jobs;
    void recc(int i, int mx){
        if(i==n){
            ans = min(ans, mx);
            return;
        }
        if(mx>=ans)return;
        
        // make a new partition
        if(partitions.size()<k)
        {    
            partitions.push_back(jobs[i]);
            recc(i+1, max(mx, jobs[i]) );
            partitions.pop_back();
            
        }

        // assign to the jth partition //
        for(int j=0;j<partitions.size();++j){
            partitions[j] += jobs[i];
            recc(i+1, max(mx, partitions[j]) );
            partitions[j] -= jobs[i];
        }
            
        
    }
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        n = jobs.size();
        Solution::k = k;
        Solution::jobs = jobs;
        ans = accumulate(jobs.begin(), jobs.end(), 0);
        // approach // all possible partitions //
        recc(0, 0); 
        
        return ans;
    }
};