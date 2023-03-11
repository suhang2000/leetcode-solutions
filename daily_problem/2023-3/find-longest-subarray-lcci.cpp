/*
面试题 17.05. 字母与数字
https://leetcode.cn/problems/find-longest-subarray-lcci/
*/

#include "vector"
#include <cctype>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<string> findLongestSubarray(vector<string> &array) {
    int l = 0, r = 0, s = 0;
    unordered_map<int, int> map;
    map[0] = 0;
    for (int i = 1; i <= array.size(); ++i) {
      string &str = array[i - 1];
      if (isdigit(str[0])) {
        s++;
      } else {
        s--;
      }
      unordered_map<int, int>::const_iterator it = map.find(s);
      if (it == map.end()) {
        map[s] = i;
      } else if (i - it->second > r - l) {
        l = it->second;
        r = i;
      }
    }
    return {array.begin() + l, array.begin() + r};
  }
};