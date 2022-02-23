using pii=pair<int,int> ;
class Solution {
public:
    
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
    
    int m, n;
    string word;
    
    
    
    bool in(int x, int y){
        return (x>=0 && y>=0 && x<m && y<n);
    }   
    
    bool recc(int i, int j, int start, unordered_map<pii, int, hash_pair>& used, vector<vector<char>>& board){
        
        // base case // last letter of the word and same //
        if(!in(i,j))return 0;
        
        if(in(i, j) and used[make_pair(i, j)]==0 and board[i][j]==word[start] and start==word.length()-1 ){
            return 1;
        } 
        
        bool res=0;
        
        if(board[i][j]==word[start] and used[make_pair(i, j)]==0){
            
            used[make_pair(i, j)]=1;
            
            // for(int a=-1;a<2;++a){
            //     for(int b=-1;b<2;++b){
            //         // if( not (a==0 and b==0) )
            //         res |= recc(i-a, j-b, start+1, used, board);
            //     }
            // }    
            
            res |= recc(i-1, j, start+1, used, board);
            if(res)return res;
            res |= recc(i+1, j, start+1, used, board);
            if(res)return res;
            res |= recc(i, j-1, start+1, used, board);
            if(res)return res;
            res |= recc(i, j+1, start+1, used, board);
            
            used[make_pair(i, j)]=0; // backtrack //
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
                unordered_map<pii, int, hash_pair> used;
                res |= recc(i, j, start, used, board);  
                if(res)return res;
           }
        }
        
        return res;
    }
};