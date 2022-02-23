class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ans = []
        mp = {}; # dict
        for i,x in enumerate(nums):
            f = target-nums[i]
            if mp.get(f) != None:
                ans = ans + [mp.get(f), i]
                return ans
            mp[x] = i