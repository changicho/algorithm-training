#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Node {
  map<string, Node*> child;
  string key = "";
  bool isEnd = false;

  void insert(vector<string> words, int depth) {
    if (isEnd) {
      return;
    }
    string target = words[depth];

    if (child.find(target) != child.end()) {
      child.find(target)->second->insert(words, depth + 1);
    } else {
      Node* next = new Node;

      next->key = target;
      next->isEnd = depth + 1 == words.size();
      next->insert(words, depth + 1);

      child[target] = next;
    }
  }

  void print(int depth) {
    if (depth != 0) {
      for (int i = 0; i < depth - 1; i++) {
        cout << "--";
      }
      cout << key << '\n';
    }

    if (isEnd) {
      return;
    }

    for (auto it : child) {
      it.second->print(depth + 1);
    }
  }
};

void solution() {
  int N;
  cin >> N;

  Node trie;
  Node* root = new Node;

  int size;
  string word;

  for (int i = 0; i < N; i++) {
    cin >> size;
    vector<string> words(size);

    for (int j = 0; j < size; j++) {
      cin >> words[j];
    }
    root->insert(words, 0);
  }
  root->print(0);
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}