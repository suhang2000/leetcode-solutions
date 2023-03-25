/*
1574. 删除最短的子数组使剩余数组有序
https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/
*/

#include<vector>
#include<algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int right = n - 1;
        while (right > 0 && arr[right-1] <= arr[right]) --right;
        if (!right) return 0;
        int left = 0, ans = right;
        while (left == 0 || arr[left - 1] <= arr[left]) {
            while (right < n && arr[left] > arr[right]) {
                ++right;
            }
            ans = min(ans, right - left - 1);
            ++left;
        }
        return ans;
    }
};
