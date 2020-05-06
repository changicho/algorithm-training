#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define WORD_SIZE 10

using namespace std;

// trie node
struct TrieNode {
  struct TrieNode *children[WORD_SIZE];
  bool isEnd;

  // 삭제할 때 자식들도 전부삭제
  ~TrieNode() {
    for (int i = 0; i < 10; i++) {
      if (children[i] != NULL) {
        delete children[i];
      }
    }
  }
};

// new trie node
struct TrieNode *makeNode(void) {
  struct TrieNode *newNode = new TrieNode;

  newNode->isEnd = false;
  for (int i = 0; i < WORD_SIZE; i++) {
    newNode->children[i] = NULL;
  }

  return newNode;
}

void insertTrie(struct TrieNode *root, string key) {
  struct TrieNode *parent = root;

  for (int i = 0; i < key.length(); i++) {
    int index = key[i] - '0';

    if (!parent->children[index]) {
      parent->children[index] = makeNode();
    }

    parent = parent->children[index];
  }

  parent->isEnd = true;
}

bool searchTrie(struct TrieNode *root, string key) {
  struct TrieNode *parent = root;

  for (int i = 0; i < key.length(); i++) {
    if (parent->isEnd) {
      return true;
    }

    int index = key[i] - '0';

    parent = parent->children[index];
  }

  return false;
}

void solution() {
  bool answer = true;
  int N;
  cin >> N;

  vector<string> words(N);

  answer = true;
  struct TrieNode *root = makeNode();

  for (int i = 0; i < N; i++) {
    cin >> words[i];

    insertTrie(root, words[i]);
  }

  for (string word : words) {
    if (searchTrie(root, word)) {
      answer = false;

      break;
    }
  }

  if (answer) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  delete root;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    solution();
  }

  return 0;
}