class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        
        int cnt = 0;
        for(int j=0;j<strs[0].length();++j){
            for(int i=0;i<n-1;++i){
                if(strs[i][j] > strs[i+1][j]){
                    cnt++;
                    break;
                }
            }
        }
        
        return cnt;
    }
};