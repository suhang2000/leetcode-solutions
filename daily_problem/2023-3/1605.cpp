/*
1605. 给定行和列的和求可行矩阵
https://leetcode.cn/problems/find-valid-matrix-given-row-and-column-sums/description/
*/

#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> res(m, vector<int>(n));
        int i = 0, j = 0;
        while (i < m && j < n) {
            int rs = rowSum[i], cs = colSum[j];
            if (rs < cs) {
                res[i][j] = rs;
                colSum[j] -= res[i][j];
                ++i;
            } else {
                res[i][j] = cs;
                rowSum[i] -= res[i][j];
                ++j;
            }            
        }
        return res;
    }
};
