using vi  = vector<int> ;
class Solution {
public:
    int maximumUnits(vector<vector<int>>& a, int truckSize) {
        sort(a.begin(), a.end(), [](vi &left, vi &right){
              if(left[1]==right[1])return left[0]>right[0];
                  return left[1]>right[1];
        }); 
        
        // for(auto x: a){
        //     cout<<x[0]<<' '<<x[1]<<"\n";
        // }
        
        int cnt = 0;
        
        for(int i=0;i<a.size();++i){
            // if(a[i][0]<=truckSize){    
                cnt += min(truckSize, a[i][0])*a[i][1];
            // }
            truckSize -= min(truckSize, a[i][0]);
            if(truckSize<=0)break;
        }
        
        return cnt;
    }
};