/*
1615. 最大网络秩
https://leetcode.cn/problems/maximal-network-rank/description/
*/

#include <algorithm>
#include <unordered_set>
#include <vector>

using std::max;
using std::unordered_set;
using std::vector;

class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<unordered_set<int>> g(n);
    for (vector<int> &road : roads) {
      int x = road[0];
      int y = road[1];
      g[x].insert(y);
      g[y].insert(x);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int cur = g[i].size() + g[j].size();
        if (g[i].count(j))
          --cur;
        res = max(res, cur);
      }
    }
    return res;
  }
};