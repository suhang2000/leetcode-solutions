/*
"""
2469. 温度转换
https://leetcode.cn/problems/convert-the-temperature/description/
"""
*/

#include <vector>

using std::vector;

class Solution {
public:
  vector<double> convertTemperature(double celsius) {
    return {celsius + 273.15, celsius * 1.8 + 32};
  }
};