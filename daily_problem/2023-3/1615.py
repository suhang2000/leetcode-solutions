"""
1615. 最大网络秩
https://leetcode.cn/problems/maximal-network-rank/description/
"""


class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        g = [set() for _ in range(n)]
        for x, y in roads:
            g[x].add(y)
            g[y].add(x)
        res = 0
        for i in range(n):
            for j in range(i + 1, n):
                res = max(res, len(g[i]) + len(g[j]) - int(j in g[i]))
        return res
