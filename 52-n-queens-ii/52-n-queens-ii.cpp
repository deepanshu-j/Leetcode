#define rep(i,a,b) for(int i=a;i<b;++i)
class Solution {
public:
    int ans=0;
    int n;
    void recc(int row, vector<vector<int>>& board){
        
        if(row == n){
            ++ans;
            
            // rep(i,0,n){
            //     rep(j,0,n)cout<<board[i][j]<<" ";
            //     cout<<"\n";
            // }
            // cout<<"\n";
            return;
        }
        
        // check can you place it at this row at jth col //
        
        rep(j,0,n){
            
            bool ok=1;
            
            rep(i,0,row)if(board[i][j]){ok=0; break;}
            
            int x = row, y = j;
            while(x>=0 and y>=0 and x<n and y<n){
                if(board[x][y]){ok=0; break;}
                --x; --y;
            }
            
            x = row, y = j;
            while(x>=0 and y>=0 and x<n and y<n){
                if(board[x][y]){ok=0; break;}
                --x; ++y;
            }
            
            if(ok){
                board[row][j] = 1;
                recc(row+1, board);
                board[row][j] = 0;
            }
            
        }
        
    }
    
    int totalNQueens(int n) {
        Solution::n = n;
        vector<vector<int>> board(n, vector<int>(n));
        rep(i,0,n)rep(j,0,n)board[i][j]=0;
        
        recc(0, board);
        
        return ans;
    }
};