#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode {
  TrieNode *children[26] = {
      NULL,
  };

  string data;
  string maximum;
  int count;
  int maxCount;

  TrieNode() {
    data = "";
    count = 0;
    maximum = "";
    maxCount = 0;
  }
};

class Trie {
 private:
  TrieNode *root = new TrieNode;

 public:
  void insert(string word) {
    TrieNode *node = root;
    stack<TrieNode *> stk;

    for (char &c : word) {
      stk.push(node);

      if (!node->children[c - 'A']) {
        node->children[c - 'A'] = new TrieNode();
      }

      node = node->children[c - 'A'];
    }
    stk.push(node);

    node->count++;
    if (node->data == "") {
      node->data = word;
      node->maximum = word;
      node->maxCount = node->count;
    } else if (node->count == node->maxCount) {
      node->maximum = min(node->maximum, node->data);
    } else if (node->count > node->maxCount) {
      node->maximum = node->data;
      node->maxCount = node->count;
    }

    while (stk.size() > 0) {
      TrieNode *cur = stk.top();
      stk.pop();

      for (int i = 0; i < 26; i++) {
        TrieNode *child = cur->children[i];
        if (child == NULL) continue;

        if (cur->maxCount == child->maxCount) {
          cur->maximum = min(cur->maximum, child->maximum);
        } else if (cur->maxCount < child->maxCount) {
          cur->maximum = child->maximum;
          cur->maxCount = child->maxCount;
        }
      }
    }
  }

  TrieNode *search(string word) {
    TrieNode *node = root;

    for (char &c : word) {
      if (!node->children[c - 'A']) {
        return NULL;
      }

      node = node->children[c - 'A'];
    }

    return node;
  }
};

vector<string> solution(vector<string> &words, vector<string> &queries) {
  Trie trie;

  for (string &word : words) {
    trie.insert(word);
  }

  vector<string> ret;
  for (string &q : queries) {
    TrieNode *cur = trie.search(q);

    if (!cur) {
      ret.push_back("0");
    } else {
      string line = cur->maximum + " " + to_string(cur->maxCount);
      ret.push_back(line);
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;

  cin >> N;
  vector<string> words(N);
  for (int i = 0; i < N; i++) {
    cin >> words[i];
  }

  cin >> K;
  vector<string> queries(K);
  for (int i = 0; i < K; i++) {
    cin >> queries[i];
  }

  vector<string> answer = solution(words, queries);
  for (string &line : answer) {
    cout << line << "\n";
  }
  cout << endl;
  return 0;
}