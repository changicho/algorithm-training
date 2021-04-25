#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

// use sort (1.76)

class Solution {
 public:
  vector<int> merge(Node *root1, Node *root2) {
    vector<int> arr;

    recursive(root1, arr);
    recursive(root2, arr);

    sort(arr.begin(), arr.end());

    return arr;
  }

  void recursive(Node *cur, vector<int> &arr) {
    if (!cur) return;

    arr.push_back(cur->data);

    recursive(cur->left, arr);
    recursive(cur->right, arr);
  }
};

// use inOrder (1.08)

class Solution {
 public:
  vector<int> merge(Node *root1, Node *root2) {
    vector<int> arr;
    queue<int> first, second;

    inOrder(root1, first);
    inOrder(root2, second);

    while (!second.empty() && !first.empty()) {
      if (second.front() < first.front()) {
        arr.push_back(second.front());
        second.pop();
      } else {
        arr.push_back(first.front());
        first.pop();
      }
    }

    while (!first.empty()) {
      arr.push_back(first.front());
      first.pop();
    }

    while (!second.empty()) {
      arr.push_back(second.front());
      second.pop();
    }

    return arr;
  }

  void recursive(Node *cur, vector<int> &arr) {
    if (!cur) return;

    arr.push_back(cur->data);

    recursive(cur->left, arr);
    recursive(cur->right, arr);
  }

  void inOrder(Node *cur, queue<int> &q) {
    if (!cur) return;

    inOrder(cur->left, q);
    q.push(cur->data);
    inOrder(cur->right, q);
  }
};