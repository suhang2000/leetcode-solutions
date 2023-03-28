/*
1638. 统计只差一个字符的子串数目
https://leetcode.cn/problems/count-substrings-that-differ-by-one-character/description/
*/

#include<string>
#include<algorithm>

using std::string;
using std::max;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.length(), n = t.length();
        int ans = 0;
        for (int d = 1 - n; d < m; ++d) {
            // d = i - j
            int i = max(0, d), j = i - d;
            int f = 0, g = 0;
            while (i < m && j < n) {
                if (s[i] == t[j]) {
                    ++g;
                } else {
                    f = g + 1;
                    g = 0;
                }
                ans += f;
                ++i;
                ++j;
            }
        }
        return ans;
    }
};
