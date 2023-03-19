"""
1625. 执行操作后字典序最小的字符串
https://leetcode.cn/problems/lexicographically-smallest-string-after-applying-operations/description/
"""


class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        q = deque([s])
        state = {s}
        res = s
        while q:
            cur = q.popleft()
            res = min(res, cur)
            t1 = ''.join(str((int(x) + a) % 10) if i &
                         1 else x for i, x in enumerate(cur))
            t2 = cur[-b:] + cur[:-b]
            for t in (t1, t2):
                if t not in state:
                    state.add(t)
                    q.append(t)
        return res
