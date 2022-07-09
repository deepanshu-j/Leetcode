using ll = long long; 
class Solution {
public:
    void showq(queue<int> gq)
    {
        queue<int> g = gq;
        while (!g.empty()) {
            cout << ' ' << g.front();
            g.pop();
        }
        cout << '\n';
    }
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1)return nums[0];
        
        queue<int> q;
        multiset<int> s;
        q.push(nums[n-1]);
        s.insert(nums[n-1]);
        int ans;
        int i = n-2;
        while(i>=0){
            // cout<<"i:"<<i<<"\n";
            // showq(q);
            // for(auto x: s)cout<<x<<" ";
            // cout<<"\n";
            
            if(q.size()==k+1){
                int fr = q.front();
                q.pop();
                s.erase(s.find(fr));
            }
            
            int mx = *s.rbegin();
            ans = nums[i]+mx;
            
            q.push(ans);
            s.insert(ans);
            --i;
        }
        
        return q.back();
    }
};