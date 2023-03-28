"""
1032. 字符流
https://leetcode.cn/problems/stream-of-characters/description/
"""

from collections import defaultdict
from typing import List

class Trie:
    def __init__(self):
        self.children = defaultdict(Trie)
        self.end = False
    
    def insert(self, word):
        cur = self
        for i in range(len(word) - 1, -1, -1):
            x = word[i]
            cur = cur.children[x]
        cur.end = True
    
    def find(self, flow):
        cur = self
        for i in range(len(flow) - 1, -1, -1):
            x = flow[i]
            if cur.end:
                return True
            if x not in cur.children:
                return False
            cur = cur.children[x]
        return cur.end


class StreamChecker:

    def __init__(self, words: List[str]):
        self.trie = Trie()
        for word in words:
            self.trie.insert(word)
        self.flow = []

    def query(self, letter: str) -> bool:
        self.flow.append(letter)
        return self.trie.find(self.flow)



# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)