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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// use DFS & heap
// time : O(N * log_2(K))
// space : O(N + K)
class Solution {
 private:
  priority_queue<int, vector<int>, greater<int>> pq;

  // {isPerfect, count}
  pair<bool, int> recursive(TreeNode *node, int k) {
    int count = 1;

    bool isPerfect = true;
    int leftCount = 0, rightCount = 0;
    if (node->left) {
      auto ret = recursive(node->left, k);

      if (!ret.first) isPerfect = false;
      leftCount = ret.second;
    }
    if (node->right) {
      auto ret = recursive(node->right, k);

      if (!ret.first) isPerfect = false;
      rightCount = ret.second;
    }

    if (leftCount != rightCount) {
      isPerfect = false;
    }
    count += leftCount + rightCount;

    if (isPerfect) {
      pq.push(count);
      if (pq.size() > k) pq.pop();
    }

    return {isPerfect, count};
  }

 public:
  int kthLargestPerfectSubtree(TreeNode *root, int k) {
    if (root) recursive(root, k);

    if (pq.size() < k) return -1;

    return pq.top();
  }
};