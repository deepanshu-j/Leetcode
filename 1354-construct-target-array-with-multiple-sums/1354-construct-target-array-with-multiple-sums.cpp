#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define debugvec(x) cout<<#x<<": [ ";\
        for(ll iii=0;iii<x.size();++iii)\
        if(iii<x.size()-1)cout<<x[iii]<<" ,";else cout<<x[iii];\
        cout<<" ]\n";
class Solution {
public:
    
    // 1 1 1 -> sum=3
    // anyone replaced will definately be 3 //
    // 1 3 1 -> means sum=prevsum-1+3=5 
    // now there are 2 options replace another 1 or 3 //
    // also you just need to tell if its possble or not //
    
    
    bool isPossible(vector<int>& target) {
        // find the largest // replace it with the the sum of all other except this //
        
        // the main obs is that this operation s if appliced on some a[i] means nothing but adding the sum of arr except a[i] to this a[i]
        // and from here its easy to see the largest one would be probably the last one to be mdified .. hence 
        
        // eg 9 3 5
        //    1 3 5 // as 9 is the largest 9-8 
        //    1 3 1 // as 5 is the largest replace 5 with 5-
        //    1 1 1 // 
        long long sum = accumulate(target.begin(), target.end(), 0LL);

        multiset<long long> s;
        int n = target.size();
        for(auto x: target)s.insert(-1*x);
        bool ok = 1;
        while(1){
            
            // cout<<"SET\n";
            // for(auto x: s)cout<<x<<" ";
            // cout<<"\n";
            
            long long value = ( *s.begin() );
            // debug(value)
            auto itr = s.find(value);
            if(itr!=s.end())    s.erase(itr);
            else{
                ok=0;
                break;
            }
            
            long long sec_largest = -1*( *s.begin() );
            
            // make it smaller until its not lt the sec largest //
            value *= -1;
            long long prev_val = value;
            if(prev_val==1)break;
            
            // sec_largets <= prev_val
            // prev_val - k * s^ >= sec_largest
            // prev_val -sec_largest / s^ >= k 
            
            long long sub = sum - prev_val;
            if(sub==0){
                ok=0;
                break;
            }
            long long k = (prev_val - sec_largest)/sub + ((prev_val - sec_largest)%sub!=0);
            if(k==0)++k;
            long long new_val  = prev_val - k * sub;
            sum = sum - prev_val + new_val;
            
            s.insert(-1*new_val);
            if(new_val<1){
                ok=0; break;
            }
            
            if(sum<=n)break;
        }
        
        return ok;
    }
};