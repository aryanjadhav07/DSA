class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        count = 0
        maxcount = 0
        for num in nums:
            if num == 1:
                count += 1
                maxcount = max(maxcount, count)
            else:
                count = 0
        return maxcount