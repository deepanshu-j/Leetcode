#define vi vector<int> 
class Solution {
public:
    int inf = 0x3f3f3f3f;
    int bs1(vi v, int target){
        
        int sz=v.size();
        int l = 0, r = sz-2;
        
        while(l<=r){
        
            int mid = (l+r)/2;
            // it belongs to this range // 
            if(v[mid]<=target and target<v[mid+1])return mid;
            else
            if(target < v[mid]) r = mid-1;
            else 
            if(target >= v[mid+1]) l = mid+1;
            
        }
        return -1;
    }
    
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        // m X n matrix // 
        // if(target<matrix[0][0] or target>matrix[m-1][n-1])return 0;

        vi row;
        for(int i=0; i<m; ++i){
            row.emplace_back(matrix[i][0]);
        }
        row.emplace_back(inf);
        
        int row_idx = bs1(row, target);
        
        // cout<<row_idx<<"\n";
        // not possible though //
        if(row_idx==-1)return 0;
        
        
        row = matrix[row_idx];
        
        return binary_search(row.begin(), row.end(), target);
        
        
    }
};