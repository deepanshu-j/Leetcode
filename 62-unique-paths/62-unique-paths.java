class Solution {
    
    Boolean flag = true;
    int[][] cache = new int[101][101];
    
    private void pre(){
        
        for(int i=0;i<101;++i)
            for(int j=0;j<101;++j)
                cache[i][j] = -1;
        
    }
    
    
    public int uniquePaths(int m, int n) {
        if(m==1 || n==1)return 1;
        
        if(flag){
            pre();
            flag=false;
        }
        
        if(cache[m][n] != -1)return cache[m][n];
        
        return cache[m][n] = uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
}