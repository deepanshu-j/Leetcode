class Solution {
public:
    
    void show_pq(priority_queue<int> pq){
        priority_queue<int> q = pq;
        
        cout<<"\nPriority queue\n";
        while(!q.empty()){
            cout<<q.top()<<" ";
            q.pop();
        }
        
    }
    
    int scheduleCourse(vector<vector<int>>& arr) {
        
        sort(arr.begin(), arr.end(), [](vector<int> &l, vector<int>&r){
            if(l[1]==r[1])return l[0]<r[0];
            return l[1]<r[1];
        });
        
        // for(auto a: arr){
        //     cout<<"("<<a[0]<<","<<a[1]<<") ";
        // }
        
        int _time = 0;
        priority_queue<int> pq;
        int cnt=0;
        for(auto a: arr){
            
            // show_pq(pq);
            // cout<<"time: "<<_time<<"\n";
            
            if(_time + a[0] <= a[1]){
                pq.push(a[0]);
                _time += a[0];
                ++cnt;
            }else{

                if( !pq.empty() and pq.top() > a[0] ){
                    // if can't add then try to replace //
                    _time -= pq.top();
                    _time += a[0];
                    pq.pop();
                    pq.push(a[0]);
                }
            }
        }
        
        // show_pq(pq);
        
        return cnt;
    }
};