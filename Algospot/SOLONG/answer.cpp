#include <algorithm>
#include <climits>
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
    string branch = "";
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
      if (cur->branch == "") {
        cur->branch = word;
      }
    }

    cur->isEnd = true;
  }

  int getMinCost(string& word) {
    TrieNode* cur = root;
    int ret = word.length();
    int depth = 0;

    for (char& c : word) {
      cur = cur->children[c - 'A'];
      depth++;

      if (cur->branch == word) {
        ret = min(ret, depth + 1);
      }
    }

    return ret;
  }
};

struct Data {
  string str;
  int priority;

  bool operator<(const Data& b) const {
    if (b.priority == priority) return str < b.str;
    return priority > b.priority;
  }
};

int solution(vector<Data>& words, vector<string>& targets) {
  unordered_set<string> appears;
  sort(words.begin(), words.end());

  Trie trie;

  for (Data& word : words) {
    trie.insert(word.str);
    appears.insert(word.str);
  }

  int answer = targets.size() - 1;
  for (string& target : targets) {
    if (appears.count(target) == 0) {
      answer += target.length();
      continue;
    }

    int curCost = trie.getMinCost(target);
    answer += curCost;
  }
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  while (C--) {
    int N, M;
    cin >> N >> M;

    vector<Data> words(N);
    for (int i = 0; i < N; i++) {
      cin >> words[i].str >> words[i].priority;
    }

    vector<string> targets(M);
    for (int i = 0; i < M; i++) {
      cin >> targets[i];
    }

    int answer = solution(words, targets);

    cout << answer << "\n";
  }

  return 0;
}