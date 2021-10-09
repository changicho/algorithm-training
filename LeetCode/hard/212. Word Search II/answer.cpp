#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use trie and recursive

class Solution {
 private:
  class Trie {
   private:
    struct TrieNode {
      struct TrieNode* children[26] = {
          NULL,
      };

      bool isEnd = false;
    };

    TrieNode* root = new TrieNode;

   public:
    void insert(string word) {
      TrieNode* node = root;

      for (char c : word) {
        int index = c - 'a';
        if (!node->children[index]) {
          node->children[index] = new TrieNode;
        }

        node = node->children[index];
      }

      node->isEnd = true;
    }

    bool search(string word) {
      TrieNode* node = root;

      for (char c : word) {
        int index = c - 'a';
        if (!node->children[index]) return false;

        node = node->children[index];
      }

      return node && node->isEnd;
    }

    bool startsWith(string prefix) {
      TrieNode* node = root;

      for (char c : prefix) {
        int index = c - 'a';
        if (!node->children[index]) return false;

        node = node->children[index];
      }

      return node;
    }
  };

  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  unordered_set<string> findMap;
  Trie* trie = new Trie();
  int rows;
  int cols;

  void recursive(Axis axis, string line, vector<vector<char>>& board,
                 vector<vector<bool>>& visited) {
    if (visited[axis.y][axis.x]) return;
    visited[axis.y][axis.x] = true;

    line += board[axis.y][axis.x];

    if (line.length() > 10 || !trie->startsWith(line)) {
      visited[axis.y][axis.x] = false;
      return;
    }

    if (trie->search(line)) {
      findMap.insert(line);
    }

    for (Axis dir : dirs) {
      Axis next = {axis.y + dir.y, axis.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x]) continue;

      recursive(next, line, board, visited);
    }

    visited[axis.y][axis.x] = false;
  }

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    rows = board.size();
    cols = board.front().size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (string word : words) {
      trie->insert(word);
    }

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        recursive({y, x}, "", board, visited);
      }
    }

    vector<string> answer;
    for (string word : findMap) {
      answer.emplace_back(word);
    }
    return answer;
  }
};

// use trie and recursive with trieNode

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
        int index = c - 'a';

        if (!cur->children[index]) {
          cur->children[index] = new TrieNode();
        }
        cur = cur->children[index];
      }

      cur->isEnd = true;
    }

    void erase(string word) { erase(word, 0, root); }

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