/*
1630. 等差子数组
https://leetcode.cn/problems/arithmetic-subarrays/description/
*/

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> res(m, true);
        for (int idx = 0; idx < m; ++idx) {
            int i = l[idx], j = r[idx];
            vector<int> v(nums.begin() + i, nums.begin() + j + 1);
            sort(v.begin(), v.end());
            int d = v[1] - v[0];
            for (int k = 1; k < j - i; ++k) {
                if (d != v[k+1] - v[k]) {
                    res[idx] = false;
                    break;
                }
            }
        }
        return res;
    }
};
