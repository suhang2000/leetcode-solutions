"""
2395. 和相等的子数组
https://leetcode.cn/problems/find-subarrays-with-equal-sum/description/
"""

from itertools import pairwise
from typing import List


class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:
        s = set()
        for x, y in pairwise(nums):
            if x + y in s:
                return True
            s.add(x + y)
        return False
