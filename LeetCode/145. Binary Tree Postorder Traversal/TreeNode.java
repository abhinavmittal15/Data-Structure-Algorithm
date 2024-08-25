import java.util.ArrayList;
import java.util.List;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) {val= x;}
}

public class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        return dfs(root, new ArrayList());
    }
    private List<Integer> dfs(TreeNode root, List<Integer> list) {
        if(root == null) {
            return list;
        }
        list = dfs(root.left, list);
        list = dfs(root.right, list);
        list.add(root.val);
        return list;
    }
    public static void main(String[] args) {
        Solution obj = new Solution();
        TreeNode root = 1;
        root.left = null;
        root.right = 2;
        root.right.left = 3;

    }
}
