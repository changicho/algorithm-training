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
      Node* before = NULL;

      while (size--) {
        Node* cur = q.front();
        q.pop();

        cur->next = before;
        before = cur;

        if (cur->right) q.push(cur->right);
        if (cur->left) q.push(cur->left);
      }
    }

    return root;
  }
};

// use recursive find Next

class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return NULL;

    if (root->left) {
      root->left->next = root->right ? root->right : findNext(root->next);
    }

    if (root->right) {
      root->right->next = findNext(root->next);
    }

    connect(root->right);
    connect(root->left);

    return root;
  }

  Node* findNext(Node* node) {
    if (!node) return NULL;

    if (node->left) return node->left;
    if (node->right) return node->right;

    return findNext(node->next);
  }
};

// use left iteration

class Solution {
 public:
  Node* connect(Node* root) {
    Node* cur = root;

    while (cur) {
      Node *dummy = new Node(0), *child = dummy;

      while (cur) {
        if (cur->left) {
          child = child->next = cur->left;
        }
        if (cur->right) {
          child = child->next = cur->right;
        }

        cur = cur->next;
      }
      cur = dummy->next;
    }

    return root;
  }
};