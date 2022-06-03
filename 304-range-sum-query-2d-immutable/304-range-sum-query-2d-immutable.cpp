#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
class NumMatrix {
public:
    vector<vector<int>> pre;
    int n, m;
    bool check(int i, int j){
        return (i>=0 and i<n and j>=0 and j<m);
    };
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size(), m=matrix[0].size();
        pre.resize(n, vector<int>(m,0));
        
        pre[0][0] = matrix[0][0];
        rep(i,0,n){
            rep(j,0,m){
                pre[i][j] = matrix[i][j];
                if(check(i-1, j)) pre[i][j] += pre[i-1][j];
                if(check(i, j-1)) pre[i][j] += pre[i][j-1];
                if(check(i-1, j-1)) pre[i][j] -= pre[i-1][j-1];
            }
        }
       
        // rep(i,0,n){
        //     rep(j,0,m){
        //         cout<<pre[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = pre[row2][col2];
        if(check(row1-1, col2)) ans -= pre[row1-1][col2];
        if(check(row2, col1-1)) ans -= pre[row2][col1-1];
        if(check(row1-1, col1-1)) ans += pre[row1-1][col1-1];
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */