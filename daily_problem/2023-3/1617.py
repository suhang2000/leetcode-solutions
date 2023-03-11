"""
1617. 统计子树中城市之间最大距离
https://leetcode.cn/problems/count-subtrees-with-max-distance-between-cities/description/
"""


class Solution:
    def countSubgraphsForEachDiameter(self, n: int, edges: List[List[int]]) -> List[int]:
        # 0. 建图，邻接表
        g = [[] for _ in range(n)]
        for x, y in edges:
            g[x-1].append(y-1)
            g[y-1].append(x-1)
        # 1. 计算所有点之间的距离
        dis = [[0] * n for _ in range(n)]

        def dfs(i, x, fa):
            for y in g[x]:
                if y != fa:
                    dis[i][y] = dis[i][x] + 1
                    dfs(i, y, x)
        for i in range(n):
            dfs(i, i, -1)
        # 2. 再次DFS n次，每次取不同根i，枚举其余点j

        def dfs2(i, j, d, x, fa):
            cnt = 1
            for y in g[x]:
                if y != fa and (dis[i][y] < d or dis[i][y] == d and y > j) and (dis[j][y] < d or dis[j][y] == d and y > i):
                    cnt *= dfs2(i, j, d, y, x)
            if dis[i][x] + dis[j][x] > d:
                cnt += 1
            return cnt
        res = [0] * (n-1)
        for i in range(n):
            for j in range(i + 1, n):
                d = dis[i][j]
                res[d-1] += dfs2(i, j, dis[i][j], i, -1)
        return res
