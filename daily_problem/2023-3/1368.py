"""
1638. 统计只差一个字符的子串数目
https://leetcode.cn/problems/count-substrings-that-differ-by-one-character/description/
"""

class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        ans = 0
        for d in range(1 - n, m):
            # d = i - j -> j = i - d
            # 枚举每个边界条件(0, j)和(i, 0)
            i = max(d, 0)
            j = i - d
            # print(i, j)
            f = g = 0
            while i < m and j < n:
                if s[i] == t[j]:
                    g += 1
                else:
                    f = g + 1
                    g = 0
                ans += f
                i += 1
                j += 1
        return ans