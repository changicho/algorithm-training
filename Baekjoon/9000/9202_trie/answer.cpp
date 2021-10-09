#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

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
      int index = c - 'A';

      if (!cur->children[index]) {
        cur->children[index] = new TrieNode();
      }
      cur = cur->children[index];
    }

    cur->isEnd = true;
  }
};

struct Axis {
  int y, x;
};

Axis dirs[8] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

int scores[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

void recursive(vector<vector<char>>& board, Axis axis, TrieNode* node,
               string& word, Trie& trie, unordered_set<string>& answers) {
  int rows = board.size();
  int cols = board.front().size();

  char cur = board[axis.y][axis.x];
  if (cur == '*' || !node->children[cur - 'A']) return;

  word += cur;
  node = node->children[cur - 'A'];

  if (node->isEnd) {
    answers.insert(word);
  }

  // visited check
  board[axis.y][axis.x] = '*';

  for (Axis dir : dirs) {
    Axis next = {axis.y + dir.y, axis.x + dir.x};

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
    if (board[next.y][next.x] == '*') continue;
    if (!node->children[board[next.y][next.x] - 'A']) continue;

    recursive(board, next, node, word, trie, answers);
  }

  board[axis.y][axis.x] = cur;

  word.pop_back();
}

void solution() {
  int W, B;

  cin >> W;

  vector<string> words(W);
  for (int i = 0; i < W; i++) {
    cin >> words[i];
  }

  Trie trie(words);
  TrieNode* root = trie.root;

  vector<vector<char>> board(4, vector<char>(4));

  cin >> B;
  while (B--) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        cin >> board[y][x];
      }
    }

    unordered_set<string> answers;

    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        string word;
        recursive(board, {y, x}, root, word, trie, answers);
      }
    }

    string answer = "";
    int score = 0;
    for (string cur : answers) {
      score += scores[cur.length()];
      if (answer.length() < cur.length() ||
          answer.length() == cur.length() && cur < answer) {
        answer = cur;
      }
    }

    cout << score << " " << answer << " " << answers.size() << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}