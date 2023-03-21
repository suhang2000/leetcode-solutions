"""
2469. 温度转换
https://leetcode.cn/problems/convert-the-temperature/description/
"""


class Solution:
    def convertTemperature(self, celsius: float) -> List[float]:
        return [celsius + 273.15, celsius * 1.8 + 32]
