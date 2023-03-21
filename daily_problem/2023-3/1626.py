"""
1626. 无矛盾的最佳球队
https://leetcode.cn/problems/best-team-with-no-conflicts/description/
"""


class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        a = sorted(zip(scores, ages))
        n = len(scores)
        f = [0] * n
        for i in range(n):
            f[i] = a[i][0]
            for j in range(i):
                if a[j][1] <= a[i][1]:
                    f[i] = max(f[i], f[j] + a[i][0])
        return max(f)
