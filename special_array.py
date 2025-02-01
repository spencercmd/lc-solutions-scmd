# check if every adjacent pair in the array contains one even and one odd number. if all pairs
# folow this rule, the array is a special and we return true.
# otherwise, return False
class Solution:
    def isArraySpecial(self, nums):
        # if only one element, its special by default
        if len(nums) == 1:
            return True
        # check adjacent pairs
        for i in range(len(nums) - 1):
            if (nums[i] % 2 == nums[i + 1] % 2):
                return False # not special
        return True # passed checks

# check, if only one element, its special by default

# check adjacent pairs, if both even or both odd, return false

# if all pairs follow the rule, return true

# time complexity: 0(n) we only iterate through the array once
# efficient for n < 100 as given in constraints.
