class Solution {
public:
  
    int longestValidParentheses(string s) {
           //use last to store the last matched index
    int len = s.length(), maxLen = 0, last = -1;
    if (len == 0 || len == 1)
        return 0;

    //use this stack to store the index of '('
    stack<int> Stack ;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') 
            Stack.push(i);
        else {
            //if stack is empty, it means that we already found a complete valid combo
            //update the last index.
            if (Stack.empty()) {
                last = i;        
            } else {
                Stack.pop();
                //found a complete valid combo and calculate max length
                if (Stack.empty()) 
                    maxLen = max(maxLen, i - last);
                else
                //calculate current max length
                    maxLen = max(maxLen, i - Stack.top());
            }
        }
    }

    return maxLen;
    }
   
};