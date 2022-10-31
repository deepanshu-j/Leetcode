struct node{
    int x;
    int y;
    int walls_broken;
    int distance;
    node(){
        
    }
    node(int x, int y, int walls_broken, int distance){
        this->x = x;
        this->y = y;
        this->walls_broken = walls_broken;
        this->distance = distance;
    }

};

// bool operator<(const node &a, const node &b)
// {
//     if(a.distance == b.distance)
//         return (a.walls_broken < b.walls_broken);

//     return (a.distance < b.distance);
// }

// 
struct CompareDistance {
    bool operator()(const node &a, const node &b)
    {
        if(a.distance == b.distance)
            return (a.walls_broken > b.walls_broken);

        return (a.distance > b.distance);
    }
  
};
class Solution {
public:
    
    // node pr store karunga {moves, kitne_walls_break_krne_padenge_min}
    
    
    // is node pr {move = 3, 1} ya fir {5, 0}
    // iske niche wale pr {4, 2} ya fir {6, 1}
    const int inf = 1e7;
    int dist[41][41][1602];
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        for(int i=0;i<41;++i){
            for(int j=0;j<41;++j){
                for(int k = 0; k<1602; ++k){
                    dist[i][j][k] = inf;
                 }
            }
        }
        
        // for(int i=0;i<1601;++i) dist[0][0][i] = 0;

        dist[0][0][0] = 0;
        
        int m = grid.size(), n = grid[0].size();
        // cout<<"m:"<<m<<" , n"<<n<<"\n";
        auto inside = [&m, &n](int xc, int yc)->bool{
            return (xc>=0 and yc>=0 and xc<m and yc<n);
        };
        
        priority_queue<node, vector<node>, CompareDistance> pq;
        node start_node = node(0,0,0,0);
        pq.push(start_node);
        
        while(!pq.empty()){
            
            node cur = pq.top();
            // pq.erase(pq.begin());
            pq.pop();
            
            // cout<<"x:"<<cur.x<<" , "<<"y:"<<cur.y<<" , "<<cur.distance<<" , k:"<<cur.walls_broken<<'\n';
            
            // update its neighbours //
            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};            
            
            for(int i=0;i<4;++i){
                
                int next_x = cur.x + dx[i], next_y = cur.y + dy[i];
                
                int cur_k = cur.walls_broken;
                int cur_dist = dist[cur.x][cur.y][cur_k];
                
                if(inside(next_x, next_y) and cur_k<=k){
                    
                    // cout<<next_x<<" , "<<next_y<<"\n";
                    // check if its better then add into pq //
                        
                    int wall_counter = (grid[next_x][next_y] == 1);
                    int new_dist = cur_dist + 1;
                    int prev_dist = dist[next_x][next_y][cur_k+wall_counter];
                    
                    // cout<<"cur_dist:"<<cur_dist<<"\n";
                    
                    if(new_dist < prev_dist){
                        dist[next_x][next_y][cur_k + wall_counter] = new_dist;
                        pq.push(node(next_x, next_y, cur_k + wall_counter, new_dist));
                    }
                        
                }
                
            }
            
        }
        
        int ans = inf;
        for(int i=0;i<=k;++i){
            ans = min(ans, dist[m-1][n-1][i]);
        }
        
        if(ans == inf) return -1;
        return ans;
        
    }
    
};