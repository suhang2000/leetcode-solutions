/*
1616. 分割两个字符串得到回文串
https://leetcode.cn/problems/split-two-strings-to-make-palindrome/description/
*/

#include <string>

using std::string;

class Solution {
public:
  bool checkPalindromeFormation(string a, string b) {
    return check(a, b) || check(b, a);
  }

  bool check(string &a, string &b) {
    int l = 0, r = a.size() - 1;
    while (l < r && a[l] == b[r]) {
      ++l;
      --r;
    }
    return ifPalindrome(a, l, r) || ifPalindrome(b, l, r);
  }

  bool ifPalindrome(string &a, int l, int r) {
    while (l <= r && a[l] == a[r]) {
      ++l;
      --r;
    }
    return l > r;
  }
};
