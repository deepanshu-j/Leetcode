class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int n = data.size();
    
        bool ok = 1;
        
        int rem = 0;
        for(int i = 0; i<n; ++i){
            
            if(rem == 0 and (data[i]&(1<<7)) and (data[i]&(1<<6))==0 ){
                ok = 0;
                break;
            }
            
            if(rem>0){
                
                if( (data[i]&(1<<7))
                   and (data[i]&(1<<6)) == 0 ) {
                    rem--;
                }else{
                    ok = 0;
                    break;
                }
                
            }
            else
            if( (data[i]&(1<<7)) and (data[i]&(1<<6)) and (data[i]&(1<<5)) and (data[i]&(1<<4))
                and (data[i]&(1<<3))==0 ){
                rem = 3;
            }else
            if( (data[i]&(1<<7)) and (data[i]&(1<<6)) and (data[i]&(1<<5))
                and (data[i]&(1<<4))==0) {
                rem = 2;
            }
            else
            if( (data[i]&(1<<7)) and (data[i]&(1<<6)) 
              and (data[i]&(1<<5))==0
              ){
               rem = 1; 
            }
            else
            if( (data[i]&(1<<7))==0 ){
                rem = 0;
            }
            else{
                ok = 0;
                break;
            }
            
        }
        
        if(rem>0){
            ok = 0;
        }
        
        return ok;
    }
};