using pii=pair<int,int> ;
class Solution {
public:
    
    int m, n;
    string word;
    
    
    
    bool in(int x, int y){
        return (x>=0 && y>=0 && x<m && y<n);
    }   
    
    bool recc(int i, int j, int start, vector<vector<char>>& board){
        
        // base case // last letter of the word and same //
        if(!in(i,j))return 0;
        
        if(in(i, j) and board[i][j]==word[start] and start==word.length()-1 ){
            return 1;
        } 
        
        bool res=0;
        
        if(board[i][j]==word[start]){
            
            // used[make_pair(i, j)]=1;
            char stored=board[i][j];
            board[i][j]='X';
            
            res |= recc(i-1, j, start+1, board);
            if(res)return res;
            res |= recc(i+1, j, start+1, board);
            if(res)return res;
            res |= recc(i, j-1, start+1, board);
            if(res)return res;
            res |= recc(i, j+1, start+1, board);
            
            
            board[i][j]= stored;
            // used[make_pair(i, j)]=0; // backtrack //
        }
        
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word_local) {
        
        word=word_local;
        
        // m X n board
        m=board.size();
        n=board[0].size();
        
        bool res=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                
                int start=0; // if start==word.len-1 and this is also same break as full word has occured//
               
                res |= recc(i, j, start, board);  
                if(res)return res;
           }
        }
        
        return res;
    }
};