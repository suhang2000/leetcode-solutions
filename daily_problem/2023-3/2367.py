"""
2367. 算术三元组的数目
https://leetcode.cn/problems/number-of-arithmetic-triplets/description/
"""


class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        s = set(nums)
        return sum(1 if (x - diff) in s and (x + diff) in s else 0 for x in nums)
