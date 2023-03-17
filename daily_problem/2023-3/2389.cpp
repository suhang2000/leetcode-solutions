/*
2389. 和有限的最长子序列
https://leetcode.cn/problems/longest-subsequence-with-limited-sum/description/
*/

#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int n = nums.size(), m = queries.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i+1] = s[i] + nums[i];
        }
        for (int &q : queries) {
            int l = 0, r = n;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (s[mid] > q) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            res.emplace_back(r);
        }
        return res;
    }
};
