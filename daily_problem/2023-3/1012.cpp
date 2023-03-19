/*
1012. 至少有 1 位重复的数字
https://leetcode.cn/problems/numbers-with-repeated-digits/description/
*/

#include <cstring>
#include <functional>
#include <string>

using std::function;
using std::memset;
using std::string;
using std::to_string;

class Solution {
public:
  int numDupDigitsAtMostN(int n) {
    string s = to_string(n);
    int m = s.length();
    int dp[m][1 << 10];
    memset(dp, -1, sizeof(dp));
    function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit,
                                                bool is_num) -> int {
      if (i == m) {
        return is_num;
      }
      if (!is_limit && is_num && dp[i][mask] != -1) {
        return dp[i][mask];
      }
      int res = 0;
      if (!is_num) {
        res += f(i + 1, mask, false, false);
      }
      int low = is_num ? 0 : 1;
      int up = is_limit ? s[i] - '0' : 9;
      for (int d = low; d <= up; ++d) {
        if ((mask >> d & 1) == 0) {
          res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
        }
      }
      if (!is_limit && is_num) {
        dp[i][mask] = res;
      }
      return res;
    };
    return n - f(0, 0, true, false);
  }
};
