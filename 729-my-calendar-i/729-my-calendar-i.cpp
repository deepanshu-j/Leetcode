#define pii pair<int,int> 
#define pb push_back
class MyCalendar {
public:
    vector<pii> ranges;
    vector<int> starts;
    
    bool book(int start, int end) {
        if(ranges.size()==0){
            ranges.pb({start, end});
            starts.pb(start);
            return true;
        }    
        
        int idx = lower_bound(starts.begin(), starts.end(), start) - starts.begin();
        
        int bias = 2;
        
        int i = (idx - bias>=0 )? idx-bias : 0 ;
        int lim = (idx+bias<ranges.size()) ? idx+bias : ranges.size();
        
        for( ; i<lim; ++i ){
            int s = ranges[i].first;
            int e = ranges[i].second;
              if( (( start>= s && start< e ) || (end-1 >= s && end-1< e)) ||
           (( s>= start && s< end ) || ( e-1>= start && e-1< end))
           ){
                return false;
            }
        }
        
        //no overlap//
        
        auto itPos = ranges.begin() + idx;
        auto newIt = ranges.insert(itPos, {start, end});
        
        auto itPos2 = starts.begin() + idx;
        auto newIt2 = starts.insert(itPos2, start);
        
        
//         for(auto x: ranges){
//             int s = x.first;
//             int e = x.second;
//          if( (( start>= s && start< e ) || (end-1 >= s && end-1< e)) ||
//            (( s>= start && s< end ) || ( e-1>= start && e-1< end))
//            )
//             // if( !(start >= e || s >= end) )
//                 return false;
//         }
        
//         ranges.pb({start, end});
        
        return true;
    }
};

// starts [10,20] 


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */