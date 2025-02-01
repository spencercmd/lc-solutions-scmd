class Solution(object):
# need to determine n missing dice rolls such that the overall mean remains exactly
# equal to the given mean

    def missingRolls(self, rolls, mean, n):
    # compute required total sum
        m = len(rolls)
        total_rolls = n + m
        total_sum = mean * total_rolls #required sum
        sum_known = sum(rolls) #sum of known, explicit rolls
        missing_sum = total_sum - sum_known #sum of missing rolls

    # check if it's possible to have n missing rolls
        if missing_sum < n or missing_sum > 6 * n:
            return [] #impossible case
    # distribute missing sum across n rolls
        base_value = missing_sum // n #integer division
        extra = missing_sum % n #remaining sum to distribute

    # create result array where 'extra' elements get 'base_value +1'
        result = [base_value + 1] * extra + [base_value] * (n - extra)

        return result

# compute required total sum
# check if distribution is possible
# each missing roll must be between 1 and 6, so check the bounds
# evenly distribute missing sum.
# complexity = 0(m) where m is the number of rolls

