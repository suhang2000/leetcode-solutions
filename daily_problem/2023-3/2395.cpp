/*
2395. 和相等的子数组
https://leetcode.cn/problems/find-subarrays-with-equal-sum/description/
*/

#include<vector>
#include<unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (s.count(nums[i] + nums[i + 1])) {
                return true;
            }
            s.insert(nums[i] + nums[i + 1]);
        }
        return false;
    }
};
