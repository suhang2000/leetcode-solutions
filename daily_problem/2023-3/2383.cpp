/*
2383. 赢得比赛需要的最少训练时长
https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/
*/

#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
public:
  int minNumberOfHours(int initialEnergy, int initialExperience,
                       vector<int> &energy, vector<int> &experience) {
    int exp = 0, cur = 0;
    for (int &x : experience) {
      if (cur <= x) {
        exp += x + 1 - cur;
        cur = x + 1;
      }
      cur += x;
    }
    int ene = 1;
    for (int &x : energy) {
      ene += x;
    }
    return max(0, exp - initialExperience) + max(0, ene - initialEnergy);
  }
};