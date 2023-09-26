#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;
  Node* random;
  Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
  Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
  Node(int x, Node* left, Node* right, Node* random)
      : val(x), left(left), right(right), random(random) {}
};

struct NodeCopy {
  int val;
  NodeCopy* left;
  NodeCopy* right;
  NodeCopy* random;
  NodeCopy() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
  NodeCopy(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
  NodeCopy(int x, NodeCopy* left, NodeCopy* right, NodeCopy* random)
      : val(x), left(left), right(right), random(random) {}
};

// use recursive
// time : O(N)
// space : O(N)
class Solution {
 private:
  unordered_map<Node*, NodeCopy*> cache;

  NodeCopy* recursive(Node* node) {
    if (!node) return NULL;
    // cache hit
    if (cache.count(node) > 0) return cache[node];

    NodeCopy* ret = new NodeCopy(node->val);
    cache[node] = ret;

    ret->left = recursive(node->left);
    ret->right = recursive(node->right);
    ret->random = recursive(node->random);
    return ret;
  }

 public:
  NodeCopy* copyRandomBinaryTree(Node* root) {
    NodeCopy* ret = recursive(root);
    return ret;
  }
};