/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        
        if(root1 == null && root2 == null)return null;
        
        Integer new_val = 0;
        
        if(root1 != null) new_val += root1.val;
        if(root2 != null) new_val += root2.val;
        
        TreeNode new_node = new TreeNode(new_val);
        
        new_node.left = mergeTrees( (root1!=null ? root1.left : null ), (root2!=null ? root2.left : null )  );
        
        new_node.right = mergeTrees( (root1!=null ? root1.right : null), (root2!=null ? root2.right : null) );
        
        return new_node;
    }
}