class NumArray {
public:
    
    int len, n;
    vector<int> bucket;
    vector<int> nums;
    
    NumArray(vector<int>& nums) {
        
        this->nums = nums;
        this->n = nums.size();
        this->len = sqrt(n)+1;
        bucket.resize(len, 0);
        
        for(int i=0;i<n;++i){
            bucket[i/len] += nums[i];
        }
    }
    
    void update(int index, int val) {
        bucket[index/len] -= nums[index];
        nums[index] = val;
        bucket[index/len] += nums[index];
    }
    
    int sumRange(int left, int right) {
        
        int range_sum = 0;

        for(int i=left; i<=right;){
            if(i%len == 0 and i+len-1<=right){
                range_sum += bucket[i/len];
                i+=len;
            }else{
                range_sum += nums[i];
                ++i;
            }
        }
        return range_sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */