# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def recc(self, i, j, nums)->Optional[TreeNode]:
        if i<0 or j>=len(nums) or j<0 or i>=len(nums) or i>j:
            return None
        
        if i==j:
            node = TreeNode(nums[i])
            return node
        
        # find the index of the max el #
        mx = -1
        idx= -1
        for k in range(i, j+1):
            if nums[k]>=mx:
                mx=nums[k]
                idx=k
        left = self.recc(i, idx-1, nums)
        right = self.recc(idx+1, j, nums)
        
        this_node = TreeNode(nums[idx], left, right)
        return this_node
        
    
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        return self.recc(0, len(nums)-1, nums)
        