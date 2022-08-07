class Solution {
public:
    int n;
    const int MOD = 1e9 + 7; 
    int cache[20001][30];
    long long dp(int i, char prev){
        
        if(i == n){
            return 1;
        }
        
        int val = prev - 'a';
        if(cache[i][val] !=-1 )return cache[i][val];
        
        // what can we put here //
        long long ans = 0;
        if(prev == 'a'){
            ans = dp(i+1, 'e');
        }else if(prev == 'e'){
            ans = dp(i+1, 'a') + dp(i+1, 'i');
        }
        else if(prev == 'i'){
            ans = dp(i+1, 'a') + dp(i+1, 'e') + dp(i+1, 'o') +dp(i+1, 'u');
        }
        else if(prev=='o'){
            ans = dp(i+1, 'i') + dp(i+1, 'u');
        }
        else if(prev == 'u'){
            ans = dp(i+1, 'a');    
        }else{
            ans = dp(i+1, 'a') + dp(i+1, 'e') + dp(i+1, 'i') + dp(i+1, 'o') +dp(i+1, 'u');
        }
        
        ans %= MOD;
        
        return cache[i][val] = ans;
    }
    
    int countVowelPermutation(int n) {
        this->n = n;
        memset(cache, -1, sizeof cache);
        long long ans = dp(0, 'z');
        ans %= MOD;
        return ans;
    }
};