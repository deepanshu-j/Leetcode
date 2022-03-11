#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
#define pb push_back
class Solution {
public:
    
    class dsu{
        
        public:
        
        int parent[1000];
        int _rank[1000];
        
        dsu(int lim){
            rep(i,1,lim+1){
                parent[i]=i;
                _rank[i]=0;
            } 
        }
        
        void initialize(int lim){
            //if there are n nodes , then this fn will make sure every node's parent is he himself//
            // and _rank of every node is 0 initially//
            rep(i,1,lim+1){
                parent[i]=i;
                _rank[i]=0;
            } 
        }

        int findParent(int node){
            if(node==parent[node])
                return node;

            return findParent(parent[node]);
            // return parent[node]= findParent(parent[node]); // With Path Compression//
        }

        void unionOperation(int u, int v){
            u = findParent(u);
            v = findParent(v);
            if(_rank[u]<_rank[v]){
                parent[u]=v; 
            }
            else 
            if(_rank[v]<_rank[u]){
                parent[u]=v;
            }
            else{
                parent[v]=u;
                ++_rank[v];
            }

        }

        bool doesBelongToSameSet(int u, int v){
            return (findParent(u)==findParent(v));
        }

    };
    
    int findCircleNum(vector<vector<int>>& M) {
        
        dsu ds(210);//=new dsu(210);
        for(int i=0;i<M.size();++i){
            for(int j=0;j<M[0].size();++j){
                if(M[i][j])
                    ds.unionOperation(i+1,j+1);
            }
        }
        
        set<int> res;
        
        rep(i,1,M.size()+1){
            res.insert(ds.findParent(i));
        }
        
        return res.size();
    }
};