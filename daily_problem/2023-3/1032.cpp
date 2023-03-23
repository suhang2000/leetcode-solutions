/*
1032. 字符流
https://leetcode.cn/problems/stream-of-characters/description/
*/

#include<vector>
#include<string>

using std::vector;
using std::string;

// version 1
// trie by array

const int N = 2000 * 210, M = 40010;

class StreamChecker {
private:
    int children[N][26], idx;
    bool is_end[N];
    string s;
public:
    void insert(string& word) {
        int p = 0;
        for (int i = word.length() - 1; i >= 0; --i) {
            int c = word[i] - 'a';
            if (!children[p][c]) {
                children[p][c] = ++idx;
            }
            p = children[p][c];
        }
        is_end[p] = true;
    }

    StreamChecker(vector<string>& words) {
        memset(children, 0, sizeof children);
        memset(is_end, 0, sizeof is_end);
        idx = 0;
        for (auto &word : words) {
            insert(word);
        }
    }
    
    bool query(char letter) {
        s += letter;
        int p = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            int c = s[i] - 'a';
            if (is_end[p])  return true;
            if (!children[p][c])    return false;
            p = children[p][c];
        }
        return is_end[p];
    }
};

// version 2
// trie by class

class Trie
{
private:
    Trie* children[26];
    bool is_end;
public:
    Trie() {
        is_end = false;
        for (size_t i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        
    }

    void insert(string& word) {
        Trie* cur = this;
        for (int i = word.length() - 1; i >= 0; --i)
        {
            int c = word[i] - 'a';
            if (cur->children[c] == nullptr) {
                cur->children[c] = new Trie();
            }
            cur = cur->children[c];
        }
        cur->is_end = true;
        
    }

    bool find(string& s) {
        Trie* cur = this;
        for (int i = s.length() - 1; i >= 0; --i) {
            int c = s[i] - 'a';
            if (cur->children[c] == nullptr)    return false;
            cur = cur->children[c];
            if (cur->is_end) return true;
        }
        return false;
    }
};

class StreamChecker {
private:
    Trie* trie;
    string s;

public:
    StreamChecker(vector<string>& words) {
        trie = new Trie();
        for (string& word : words) {
            trie->insert(word);
        }
    }
    
    bool query(char letter) {
        s += letter;
        return trie->find(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
