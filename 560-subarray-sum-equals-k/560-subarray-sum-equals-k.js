/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
     let sum=0, res=0;
     let n=nums.length;

     var mp = new Map();

     for(let i=0;i<n;++i){
        sum+=nums[i];
        if(mp.get(sum-k))
        res+=mp.get(sum-k);
        if(sum==k)++res;
         
        let prev=mp.get(sum);
        
        if(prev==undefined)
        mp.set(sum, 1);
        else mp.set(sum, prev+1);
     }

    return res;
};