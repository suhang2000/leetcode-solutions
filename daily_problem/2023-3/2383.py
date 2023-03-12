"""
2383. 赢得比赛需要的最少训练时长
https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/
"""


class Solution:
    def minNumberOfHours(self, initialEnergy: int, initialExperience: int, energy: List[int], experience: List[int]) -> int:
        exp = cur = 0
        for x in experience:
            if cur <= x:
                exp += x + 1 - cur
                cur = x + 1
            cur += x
        return max(exp - initialExperience, 0) + max(sum(energy) + 1 - initialEnergy, 0)
