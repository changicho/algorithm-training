#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Trie {
 private:
  struct TrieNode {
    TrieNode* children[26] = {
        NULL,
    };
    bool isEnd = false;
  };

  TrieNode* root = new TrieNode;

 public:
  Trie() {}

  void insert(string& word) {
    TrieNode* cur = root;

    for (char& c : word) {
      if (cur->children[c - 'A'] == NULL) {
        cur->children[c - 'A'] = new TrieNode;
      }
      cur = cur->children[c - 'A'];
    }

    cur->isEnd = true;
  }

  bool search(string word) {
    TrieNode* cur = root;

    for (char& c : word) {
      if (cur->children[c - 'A'] == NULL) {
        return false;
      }
      cur = cur->children[c - 'A'];
    }

    return cur->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode* cur = root;

    for (char& c : prefix) {
      if (cur->children[c - 'A'] == NULL) {
        return false;
      }
      cur = cur->children[c - 'A'];
    }
    return true;
  }
};

struct Axis {
  int y, x;
};

Axis dirs[8] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

int scores[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

void recursive(string board[4], Axis axis, string& path, Trie& trie,
               unordered_set<string>& answers) {
  char cur = board[axis.y][axis.x];
  if (cur == '*') return;
  if (!trie.startsWith(path)) return;

  path += cur;
  if (trie.search(path)) answers.insert(path);

  // visited check
  board[axis.y][axis.x] = '*';
  for (Axis dir : dirs) {
    Axis next = {axis.y + dir.y, axis.x + dir.x};

    if (next.y < 0 || next.y >= 4 || next.x < 0 || next.x >= 4) continue;
    if (board[next.y][next.x] == '*') continue;

    recursive(board, next, path, trie, answers);
  }
  board[axis.y][axis.x] = cur;
  path.pop_back();
}

void solution() {
  int W, B;
  cin >> W;

  vector<string> words(W);
  for (int i = 0; i < W; i++) {
    cin >> words[i];
  }

  Trie trie;
  for (string& word : words) {
    trie.insert(word);
  }

  string board[4] = {};

  cin >> B;
  while (B--) {
    for (int y = 0; y < 4; y++) {
      cin >> board[y];
    }

    unordered_set<string> answers;

    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        string path;
        recursive(board, {y, x}, path, trie, answers);
      }
    }

    string longest = "";
    int score = 0;
    for (string cur : answers) {
      score += scores[cur.length()];
      if (longest.length() < cur.length() ||
          longest.length() == cur.length() && cur < longest) {
        longest = cur;
      }
    }

    cout << score << " " << longest << " " << answers.size() << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  solution();

  return 0;
}