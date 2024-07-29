/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func checkTree(root *TreeNode) bool {

	if root == nil {
		return true
	}
	sum := 0
	if root.Left != nil {
		sum += root.Left.Val
	}
	if root.Right != nil {
		sum += root.Right.Val
	}
	if sum == root.Val {
		return true
	} else {
		return false
	}
	sum = 0
	return checkTree(root.Left) && checkTree(root.Right)
}