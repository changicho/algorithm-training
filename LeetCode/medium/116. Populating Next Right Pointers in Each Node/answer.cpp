#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// use BFS

class Solution {
 public:
  Node* connect(Node* root) {
    queue<Node*> q;
    if (root) q.push(root);

    while (!q.empty()) {
      int size = q.size();
      Node* next = NULL;
      while (size--) {
        Node* cur = q.front();
        q.pop();

        cur->next = next;
        next = cur;
        if (cur->right) q.push(cur->right);
        if (cur->left) q.push(cur->left);
      }
    }

    return root;
  }
};

// use recursive

class Solution {
 public:
  Node* connect(Node* root) {
    if (root) helper(root->left, root->right);

    return root;
  }

  void helper(Node* node1, Node* node2) {
    if (node1 == NULL) return;

    node1->next = node2;
    helper(node1->left, node1->right);
    helper(node2->left, node2->right);
    helper(node1->right, node2->left);
  }
};

// use left start

class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return NULL;

    Node* pre = root;
    while (pre->left) {
      Node* cur = pre;

      while (cur) {
        cur->left->next = cur->right;
        if (cur->next) {
          cur->right->next = cur->next->left;
        }
        cur = cur->next;
      }

      pre = pre->left;
    }

    return root;
  }
};
