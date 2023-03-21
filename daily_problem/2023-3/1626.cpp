/*
1626. 无矛盾的最佳球队
https://leetcode.cn/problems/best-team-with-no-conflicts/description/
*/

#include <algorithm>
#include <utility>
#include <vector>

using std::max;
using std::max_element;
using std::pair;
using std::sort;
using std::vector;

class Solution {
public:
  int bestTeamScore(vector<int> &scores, vector<int> &ages) {
    int n = scores.size();
    pair<int, int> p[n];
    for (int i = 0; i < n; ++i) {
      p[i] = {ages[i], scores[i]};
    }
    sort(p, p + n);
    int f[n];
    for (int i = 0; i < n; ++i) {
      f[i] = p[i].second;
      for (int j = 0; j < i; ++j) {
        if (p[j].second <= p[i].second) {
          f[i] = max(f[i], f[j] + p[i].second);
        }
      }
    }
    return *max_element(f, f + n);
  }
};
