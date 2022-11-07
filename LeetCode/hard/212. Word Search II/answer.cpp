#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use trie and recursive with trieNode
// time : O(R \* C \* 4^L \* L)
// space : O(N)
class Solution {
 private:
  class TrieNode {
   public:
    TrieNode* children[26] = {
        NULL,
    };
    bool isEnd = false;

    ~TrieNode() { delete *children; }
  };

  class Trie {
   private:
    void erase(string& word, int index, TrieNode* cur) {
      int length = word.length();

      if (index == length) {
        cur->isEnd = false;
        return;
      }

      int key = word[index] - 'a';
      erase(word, index + 1, cur->children[key]);
      if (isEmpty(cur->children[key])) {
        cur->children[key] = NULL;
        delete cur->children[key];
      }
    }

    bool isEmpty(TrieNode* cur) {
      for (int i = 0; i < 26; ++i) {
        if (cur->children[i]) return false;
      }
      return true;
    }

   public:
    TrieNode* root;
    Trie(vector<string>& words) {
      root = new TrieNode();
      for (string& word : words) {
        insert(word);
      }
    }

    void insert(string& word) {
      TrieNode* cur = root;

      for (char& c : word) {
        int key = c - 'a';
        if (!cur->children[key]) {
          cur->children[key] = new TrieNode();
        }
        cur = cur->children[key];
      }

      cur->isEnd = true;
    }

    void erase(string word) { erase(word, 0, root); }
  };

  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<string> answer;

  void recursive(vector<vector<char>>& board, Axis axis, TrieNode* node,
                 string& word, Trie& trie) {
    int rows = board.size();
    int cols = board.front().size();

    char cur = board[axis.y][axis.x];
    if (!node->children[cur - 'a']) return;

    word += cur;
    node = node->children[cur - 'a'];

    if (node->isEnd) {
      answer.push_back(word);
      trie.erase(word);
    }

    // visited check
    board[axis.y][axis.x] = ' ';

    for (Axis dir : dirs) {
      Axis next = {axis.y + dir.y, axis.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (board[next.y][next.x] == ' ') continue;
      if (!node->children[board[next.y][next.x] - 'a']) continue;

      recursive(board, next, node, word, trie);
    }

    board[axis.y][axis.x] = cur;

    word.pop_back();
  }

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int rows = board.size();
    int cols = board.front().size();

    Trie trie(words);
    TrieNode* root = trie.root;

    for (int y = 0; y < rows; ++y) {
      for (int x = 0; x < cols; ++x) {
        string word;
        recursive(board, {y, x}, root, word, trie);
      }
    }
    return answer;
  }
};