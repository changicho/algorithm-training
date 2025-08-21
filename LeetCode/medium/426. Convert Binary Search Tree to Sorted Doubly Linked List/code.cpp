#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node* _left, Node* _right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

// use DFS (inOrder)
// time : O(N)
// space : O(N)
class Solution {
 private:
  Node* last;

  void recursive(Node* node) {
    Node* left = node->left;
    Node* right = node->right;

    if (left) {
      recursive(left);
    }

    last->right = node;
    node->left = last;

    last = node;

    if (right) {
      recursive(right);
    }
  }

 public:
  Node* treeToDoublyList(Node* root) {
    if (!root) return NULL;

    Node* dummy = new Node(-1);
    dummy->right = root;
    last = dummy;

    recursive(root);

    dummy->right->left = last;
    last->right = dummy->right;

    return dummy->right;
  }
};