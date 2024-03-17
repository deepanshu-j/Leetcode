class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](vector<int>& l, vector<int>& r){
            if(l[0]==r[0])return l[1]<r[1];
            return l[0]<r[0];
        });
        
        vector<vector<int>> merged{a[0]};
        
        int n = a.size();
        for(int i=0; i<n; ++i){
            if(a[i][0] > merged.back()[1]){
                merged.emplace_back(a[i]);
            }else{
                merged.back()[1] = max(a[i][1], merged.back()[1]);
            }
        }
        return merged;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        return merge(intervals);
    }
};