class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> v(n*n);
        int i=0;
        for(auto x: matrix)
            for(auto y: x)
                v[i++] = y;
        
        sort(v.begin(), v.end());
        return v[k-1];
    }
};