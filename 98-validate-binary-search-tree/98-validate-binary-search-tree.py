# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def recc(self, root, mn, mx)->bool:
        if root==None:
            return True
        if root.left==None and root.right==None:
            return (mn<=root.val and root.val<=mx)
        
        if mn<=root.val and root.val<=mx:
            return self.recc(root.left, mn, root.val-1) and self.recc(root.right, root.val+1, mx)
        else:
            return False
    
    def isValidBST(self, root: TreeNode) -> bool:
        
        inf = int(2**32)
        return self.recc(root, -inf, inf)
        