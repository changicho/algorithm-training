#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* parent;
};

// use hash set

class Solution {
 public:
  Node* lowestCommonAncestor(Node* p, Node* q) {
    unordered_set<int> paths;

    while (p) {
      paths.insert(p->val);
      p = p->parent;
    }

    while (q) {
      if (paths.count(q->val) > 0) return q;

      q = q->parent;
    }

    return NULL;
  }
};

// use iterative

class Solution {
 public:
  Node* lowestCommonAncestor(Node* p, Node* q) {
    Node *first = p, *second = q;

    while (first != second) {
      first = first ? q : first->parent;
      second = second ? p : second->parent;
    }
    return first;
  }
};