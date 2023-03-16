"""
2488. 统计中位数为 K 的子数组
https://leetcode.cn/problems/count-subarrays-with-median-k/description/
"""


class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        p = nums.index(k)
        cnt = Counter({0: 1})
        c = 0
        for i in range(p-1, -1, -1):
            x = nums[i]
            c += 1 if x < k else -1
            cnt[c] += 1
        res = cnt[0] + cnt[-1]
        c = 0
        for x in nums[p+1:]:
            c += 1 if x > k else -1
            res += cnt[c] + cnt[c-1]
        return res
