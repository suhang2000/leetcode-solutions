"""
1641. 统计字典序元音字符串的数目
https://leetcode.cn/problems/count-sorted-vowel-strings/description/
"""


class Solution:
    def countVowelStrings(self, n: int) -> int:
        @cache
        def dfs(i, num):
            if i == n:
                return 1
            cur = 0
            for j in range(num, 5):
                cur += dfs(i + 1, j)
            return cur

        return dfs(0, 0)
