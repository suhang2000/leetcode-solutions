/*
1625. 执行操作后字典序最小的字符串
https://leetcode.cn/problems/lexicographically-smallest-string-after-applying-operations/description/
*/

#include <algorithm>
#include <deque>
#include <string>
#include <unordered_set>

using std::deque;
using std::min;
using std::string;
using std::unordered_set;

class Solution {
public:
  string findLexSmallestString(string s, int a, int b) {
    deque<string> q{{s}};
    unordered_set<string> state{{s}};
    string res = s;
    int n = s.size();
    while (!q.empty()) {
      string cur = q.front();
      q.pop_front();
      res = min(res, cur);
      string t1 = cur;
      for (int i = 1; i < n; i += 2) {
        t1[i] = (cur[i] - '0' + a) % 10 + '0';
      }
      string t2 = cur.substr(n - b, b) + cur.substr(0, n - b);
      for (const string &t : {t1, t2}) {
        if (!state.count(t)) {
          state.insert(t);
          q.emplace_back(t);
        }
      }
    }
    return res;
  }
};
