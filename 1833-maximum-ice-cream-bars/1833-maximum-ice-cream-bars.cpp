class Solution {
public:
    int maxIceCream(vector<int>& a, int sum) {
        sort(a.begin(), a.end());
        
        int cnt = 0;
        for(int i=0;i<a.size();++i){
            if(sum >= a[i]){ 
                sum -= a[i]; ++cnt;
            }else break;
        }
        
        return cnt;
    }
};