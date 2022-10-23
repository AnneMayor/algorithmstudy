import java.util.Collection;
import java.util.List;

public class LeetCode_PathSumII {
    
    private List<List<Integer> > res = new ArrayList();
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {

        searchPathNodes(root, 0, targetSum, res, new ArrayList());
        System.out.println("res.size: " + res.size());

        return res;
    }

    public void searchPathNodes(TreeNode node, int currentSum, int targetSum, List<List<Integer> > res, List<Integer> tempNodes) {
        if(node == null) {
            return ;
        }

        if(node.left == null && node.right == null) {
            if(currentSum + node.val == targetSum) {
                tempNodes.add(node.val);
                res.add(new ArrayList<>(tempNodes));
                tempNodes.remove(tempNodes.size()-1);
            }
            return ;
        }

        if(node.left != null) {
            tempNodes.add(node.val);
            searchPathNodes(node.left, currentSum+node.val, targetSum, res, tempNodes);
            tempNodes.remove(tempNodes.size()-1);
        }

        if(node.right != null) {
            tempNodes.add(node.val);
            searchPathNodes(node.right, currentSum+node.val, targetSum, res, tempNodes);
            tempNodes.remove(tempNodes.size()-1);
        }
    }
}
