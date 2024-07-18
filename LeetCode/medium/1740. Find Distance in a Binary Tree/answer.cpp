#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// use LCA
// time : O(N)
// space : O(N)
class Solution {
 private:
  unordered_map<int, int> parents;
  unordered_map<int, int> depths;

  void preprocess(TreeNode *node, int depth) {
    depths[node->val] = depth;

    if (node->left) {
      parents[node->left->val] = node->val;
      preprocess(node->left, depth + 1);
    }
    if (node->right) {
      parents[node->right->val] = node->val;
      preprocess(node->right, depth + 1);
    }
  }

 public:
  int findDistance(TreeNode *root, int p, int q) {
    preprocess(root, 0);

    int pDepth = depths[p], qDepth = depths[q];

    if (pDepth < qDepth) {
      swap(p, q);
      swap(pDepth, qDepth);
    }

    int answer = 0;
    while (pDepth > qDepth) {
      answer++;
      p = parents[p];
      pDepth--;
    }

    while (p != q) {
      answer += 2;
      p = parents[p];
      q = parents[q];
    }
    return answer;
  }
};

// usd DFS with distance
// time : O(N)
// space : O(N)
class Solution {
  int answer = INT_MAX;
  // pDist, qDist
  pair<int, int> recursive(TreeNode *node, int p, int q) {
    int pDist = node->val == p ? 0 : -1;
    int qDist = node->val == q ? 0 : -1;

    if (node->left) {
      pair<int, int> ret = recursive(node->left, p, q);

      if (ret.first != -1) pDist = ret.first;
      if (ret.second != -1) qDist = ret.second;
    }

    if (node->right) {
      pair<int, int> ret = recursive(node->right, p, q);

      if (ret.first != -1) pDist = ret.first;
      if (ret.second != -1) qDist = ret.second;
    }

    if (pDist != -1 && qDist != -1) {
      answer = min(answer, pDist + qDist);
    }

    if (pDist != -1) pDist++;
    if (qDist != -1) qDist++;

    return {pDist, qDist};
  }

 public:
  int findDistance(TreeNode *root, int p, int q) {
    recursive(root, p, q);

    return answer;
  }
};