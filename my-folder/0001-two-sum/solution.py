class Solution:
    def twoSum(self, nums, target):
        mp = {}
        b = []
        for i in range(len(nums)):
            if (target - nums[i]) in mp:
                b.append(i)
                b.append(mp[target - nums[i]])
                return b

            mp[nums[i]] = i
        return b
