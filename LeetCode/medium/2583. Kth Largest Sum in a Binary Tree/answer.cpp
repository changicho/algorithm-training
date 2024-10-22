#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
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

// use BFS & sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long kthLargestLevelSum(TreeNode *root, int k) {
    vector<long long> sums;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      long long curSum = 0;

      int size = q.size();
      while (size--) {
        TreeNode *cur = q.front();
        q.pop();

        curSum += cur->val;

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }
      sums.push_back(curSum);
    }

    if (sums.size() < k) return -1;
    sort(sums.begin(), sums.end(), greater<long long>());

    return sums[k - 1];
  }
};

// use BFS & heap
// time : O(N * log_2(K))
// space : O(N + K)
class Solution {
 public:
  long long kthLargestLevelSum(TreeNode *root, int k) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    queue<TreeNode *> q;
    if (root) q.push(root);

    while (!q.empty()) {
      int size = q.size();

      long long sum = 0;
      while (size--) {
        TreeNode *cur = q.front();
        q.pop();

        sum += cur->val;

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }

      pq.push(sum);
      if (pq.size() > k) pq.pop();
    }

    if (pq.size() < k) return -1;
    return pq.top();
  }
};