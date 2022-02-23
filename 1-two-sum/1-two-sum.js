/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    
    let dict = {};
    for(let i=0; i <nums.length;++i){
        let f=target-nums[i];
        if(dict[f]!==undefined){ // if(dict[f]) was giving err for [0, 0]
            let res = [i, dict[f]];
            return res;
        }
        dict[nums[i]] = i;
    }
};