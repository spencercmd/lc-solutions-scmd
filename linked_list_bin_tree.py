# depth-first search

#definition for singly linked lists

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def isSubPath(self, head, root):
        """
        :type head: Optional[ListNode]
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        if not root:
            return False #base case: empty tree
        # check if linked list matches from this root
        return (self.dfs(head, root) or
                self.isSubPath(head, root.left) or
                self.isSubPath(head, root.right))
    def dfs(self, head, node):
    # check if there is a valid path starting from node that matches the linked list
        if not head:
            return True #if we've matched the entire linked list, return true
        if not node:
            return False #if tree node is None but list still has nodes, return false
        if head.val != node.val:
            return False # if values do not match, return false
    
    # continue checking in left or right subtree

        return self.dfs(head.next, node.left) or self.dfs(head.next, node.right)

# main function, base case, if toor is none return false.
# recursive steps, try matching the list from root using dfs(head, root)
# if that fails, try from left or right subtree
# helper function dfs, base case, if head is none, return true.
# recursive search, continue to left or right child with head.next


