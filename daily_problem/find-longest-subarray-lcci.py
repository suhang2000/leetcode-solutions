"""
面试题 17.05. 字母与数字
https://leetcode.cn/problems/find-longest-subarray-lcci/
"""

class Solution:
    def findLongestSubarray(self, array: List[str]) -> List[str]:
        l = r = s = 0
        last = {s: 0}
        for i_, x in enumerate(array):
            i = i_ + 1
            s += 1 if x.isdigit() else -1
            if s in last:
                curl, curr = last[s], i
                if curr - curl > r - l:
                    l, r = curl, curr
            else:
                last[s] = i
        return array[l:r]