class Solution {
public:
    
    int n;
    vector<vector<string>> ans;
    void recc(int row, vector<string>& board){
        
        if(row==n){
            ans.emplace_back(board);
            return;
        }
        
        // recc //
        // try to put on this row //
        
        for(int j=0; j<n; ++j){
            
            // try to place on row,j if we can move forward //
            
            bool ok=1;
            
            for(int prev_row = 0;prev_row<row;++prev_row)
                if(board[prev_row][j]=='Q'){
                    ok=0;
                    break;
                }
            
            int x=row, y=j;
            while(x>=0 and y>=0 and x<n and y<n){
                if(board[x][y]=='Q'){
                    ok=0;
                    break;
                }
                x--; y--;
            }
            x = row, y = j;
            while(x>=0 and y>=0 and x<n and y<n){
                if(board[x][y]=='Q'){
                    ok=0;
                    break;
                }
                x--; y++;
            }
            
            if(ok){
                board[row][j]  = 'Q';
                recc(row+1, board);
                board[row][j]  = '.';
            }
        }
        
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        Solution::n = n;
        
        vector<string> board;
        
        string emp="";
        for(int i=0;i<n;++i)emp+=".";
        for(int i=0;i<n;++i)board.emplace_back(emp);
        
        recc(0, board);
        
        return ans;
    }
};