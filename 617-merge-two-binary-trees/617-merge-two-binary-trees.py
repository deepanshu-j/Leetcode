# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        
        if root1 == None and root2 == None: return None
        
        new_node = TreeNode(0)
        if root1 != None:   new_node.val += root1.val
        if root2 != None:   new_node.val += root2.val
        
        l = r = None
        if root1 != None:   l = root1.left
        if root2 != None:   r = root2.left
        
        new_node.left = self.mergeTrees(l, r)
        
        l = r = None
        if root1 != None:   l = root1.right
        if root2 != None:   r = root2.right
        
        new_node.right = self.mergeTrees(l, r)
        
        return new_node