"""
2389. 和有限的最长子序列
https://leetcode.cn/problems/longest-subsequence-with-limited-sum/description/
"""


class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        n, m = len(nums), len(queries)
        res = []
        s = [0] * (n + 1)
        for i in range(n):
            s[i+1] = s[i] + nums[i]
        for q in queries:
            l, r = 0, n
            while l <= r:
                mid = (l + r) >> 1
                if s[mid] > q:
                    r = mid - 1
                else:
                    l = mid + 1
            res.append(r)
        return res
