class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n=arr.size();
        
        if(n==1)return n;
        
        int cur=1+(arr[0]!=arr[1]); // contain the number of els in turbulent subarray 
        int res=cur;
        if(n==2)return cur;
        
        // i =0 means i am between 0 ans 0+1  => i and i+1 
        
        // for every new i we will either extend or start a new 
        
        for(int i=1;i<n-1;++i){
            res=max(res, cur);
            if(arr[i]==arr[i+1]){
                // start a new one //
                cur=1; 
            }else
            if(arr[i]>arr[i+1]){
                if(arr[i-1]<arr[i]){ // extend 
                    cur++;
                }else{
                    cur=2;
                } 
            }
            else{ // arr[i]<arr[i+1]
                if(arr[i-1]>arr[i]){ // extend 
                    cur++;
                }else{
                    cur=2;
                } 
            }
            res=max(res, cur);
        }
        return res;
    }
};