/*
2488. 统计中位数为 K 的子数组
https://leetcode.cn/problems/count-subarrays-with-median-k/description/
*/

#include <algorithm>
#include <unordered_map>
#include <vector>

using std::find;
using std::unordered_map;
using std::vector;

class Solution {
public:
  int countSubarrays(vector<int> &nums, int k) {
    int p = find(nums.begin(), nums.end(), k) - nums.begin();
    unordered_map<int, int> cnt{{0, 1}};
    int x = 0;
    for (int i = p - 1; i >= 0; --i) {
      x += nums[i] < k ? 1 : -1;
      cnt[x]++;
    }
    int res = cnt[0] + cnt[-1];
    x = 0;
    for (int i = p + 1; i < nums.size(); ++i) {
      x += nums[i] > k ? 1 : -1;
      res += cnt[x] + cnt[x - 1];
    }
    return res;
  }
};