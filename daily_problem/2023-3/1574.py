"""
1574. 删除最短的子数组使剩余数组有序
https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/
"""

from bisect import bisect_left
from typing import List


class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        left, right = 0, n - 1
        while right and arr[right - 1] <= arr[right]:
            right -= 1
        while left < n - 1 and arr[left] <= arr[left + 1]:
            left += 1
        if left >= right: return 0
        ans = min(right, n - left - 1)
        for l in range(left + 1):
            r = bisect_left(arr, arr[l], lo=right)
            ans = min(ans, r - l - 1)
        return ans
