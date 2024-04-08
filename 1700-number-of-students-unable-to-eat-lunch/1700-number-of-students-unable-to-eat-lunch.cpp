class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = sandwiches.size();
        int o = 0, z = 0;
        for(auto x: students) if(x==0) z++; else o++;
        
        for(int i=0;i<n;++i){
            if(sandwiches[i] == 0) z--;
            if(sandwiches[i] == 1) o--;
            if(z == -1 or o == -1) return n-i;
        }
        
        return 0;
    }
};