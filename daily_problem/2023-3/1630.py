"""
1630. 等差子数组
https://leetcode.cn/problems/arithmetic-subarrays/description/
"""

class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        n = len(nums)
        res = [True] * len(l)
        for idx, (i, j) in enumerate(zip(l, r)):
            a = sorted(nums[i:j+1])
            d = a[1] - a[0]
            for k in range(1, j - i):
                if d != a[k+1] - a[k]:
                    res[idx] = False
                    break
        return res
