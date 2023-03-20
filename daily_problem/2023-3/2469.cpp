/*
"""
2469. 温度转换
https://leetcode.cn/problems/convert-the-temperature/description/
"""
*/

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32};
    }
};