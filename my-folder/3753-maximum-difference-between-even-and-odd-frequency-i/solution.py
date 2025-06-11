class Solution:
    def maxDifference(self,s):
        maxi = 0
        mini = float('inf')
        mp = [0] * 26
        for it in s:
            mp[ord(it) - ord('a')] += 1
        for it in mp:
            if it % 2 == 1 or it == 0:
                maxi = max(maxi, it)
            else:
                mini = min(mini, it)
        return maxi - mini

        
