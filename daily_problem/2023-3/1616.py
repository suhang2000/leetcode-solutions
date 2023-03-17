"""
1616. 分割两个字符串得到回文串
https://leetcode.cn/problems/split-two-strings-to-make-palindrome/description/
"""


class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        n = len(a)

        def check(a, b):
            l, r = 0, n - 1
            while l < r and a[l] == b[r]:
                l += 1
                r -= 1
            s, t = a[l:r+1], b[l:r+1]
            return s == s[::-1] or t == t[::-1]
        return check(a, b) or check(b, a)
