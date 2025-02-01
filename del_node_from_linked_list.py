class ListNode(object): #definition for singly 
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def modifiedList(self, nums, head):
        """
        :type nums: List[int]
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        to_remove = set(nums) #convert nums list to a set for O(1) lookup

        dummy = ListNode(-1) #dummy node to simplify edge cases
        dummy.next = head
        prev, curr = dummy, head #prev tracks last valid node, curr traverses list
        while curr:
            if curr.val in to_remove:
                prev.next = curr.next #skip current node
            else:
                prev = curr #move previous to current node
            curr = curr.next #move to next node
        return dummy.next #dummy node's next points to head of modified list.

# convert nums to a set for O(k) where K is the number of elements in nums
# traverse linked list O(n) where n is the number of nodes in the list
# overall complexity = 0(n + k), efficient.

# edge cases handled
# all nodes need to be removed
# no nodes need to be removed
# only one node in the list
# use set for efficient lookups
# uses dummy node for easy list manipulation
# handles edge cases

