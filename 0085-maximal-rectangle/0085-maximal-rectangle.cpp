class Solution {
public:
    
    vector<int> findNse(vector<int> &h){
        int n = h.size();
        
        vector<int> ans(n);
        stack<int> stk;
    
        for(int i=n-1;i>=0;--i){
            
            while(!stk.empty() && h[stk.top()] >= h[i]) {
                stk.pop();
            }
            ans[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        
        return ans;
    }

    vector<int> findPse(vector<int> &h){
        int n = h.size();
        
        vector<int> ans(n);
        stack<int> stk;
        
        for(int i=0;i<n;++i){
            
            while(!stk.empty() && h[stk.top()] >= h[i]) {
                stk.pop();
            }
            
            ans[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        
        return ans;
    }
    
    int largest_rect_in_a_histogram(vector<int> &heights){
        // next smaller element //
        vector<int> nse = findNse(heights);    
        // prev smaller element //
        vector<int> pse = findPse(heights);
        
        int n = heights.size(), ans = 0;
        for(int i=0;i<n;++i){
            ans = max(ans, heights[i]*(nse[i] - pse[i] - 1));
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        /*
        1. For every row consider it as a base line and above it all the 1's as the height of the towers -> this converts the problem in largest rect in a histogram 
        2. no wuse largest_rect_in_histogram on every row
        3. update the row for next iteration
        */
        
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        
        vector<int> base(n, 0);
        for(int row=0;row<m;++row){
            for(int col = 0; col<n;++col){
                base[col] = (matrix[row][col] == '1' ? base[col] + 1: 0);
            }
            ans = max(ans, largest_rect_in_a_histogram(base));
        }
        
        return ans;
    }
};