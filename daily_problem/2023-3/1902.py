"""
1092. 最短公共超序列
https://leetcode.cn/problems/shortest-common-supersequence/description/
"""


class Solution:
    def shortestCommonSupersequence(self, s: str, t: str) -> str:
        m, n = len(s), len(t)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            f[i][0] = i
        for i in range(1, n + 1):
            f[0][i] = i
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s[i-1] == t[j-1]:
                    f[i][j] = f[i-1][j-1]
                else:
                    f[i][j] = min(f[i-1][j], f[i][j-1]) + 1

        # make answer
        res = deque()
        i, j = m, n
        while i and j:
            if s[i-1] == t[j-1]:
                res.appendleft(s[i-1])
                i -= 1
                j -= 1
            elif f[i][j] == f[i-1][j] + 1:
                res.appendleft(s[i-1])
                i -= 1
            else:
                res.appendleft(t[j-1])
                j -= 1
        return s[:i] + t[:j] + ''.join(res)
