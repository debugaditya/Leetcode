class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        b = sorted(set(nums))  # Get unique values and sort them (if required)
        
        # Modify nums in-place
        for i in range(len(b)):
            nums[i] = b[i]
        
        return len(b)



        
