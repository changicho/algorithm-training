#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
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

// use BFS
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode *root) {
    map<int, vector<int>> m;
    vector<vector<int>> ret;
    if (!root) return ret;

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
      pair<TreeNode *, int> cur = q.front();
      q.pop();

      TreeNode *node = cur.first;
      int index = cur.second;

      m[index].emplace_back(node->val);

      if (node->left) q.push({node->left, index - 1});
      if (node->right) q.push({node->right, index + 1});
    }

    for (auto &it : m) {
      ret.push_back(it.second);
    }
    return ret;
  }
};

// use hash map & BFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode *root) {
    if (!root) return {};

    unordered_map<int, vector<int>> ret;

    int left = 0;
    int right = 0;

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
      pair<TreeNode *, int> cur = q.front();
      q.pop();

      TreeNode *node = cur.first;
      int x = cur.second;
      left = min(x, left);
      right = max(x, right);

      ret[x].push_back(node->val);
      if (node->left) {
        q.push({node->left, x - 1});
      }
      if (node->right) {
        q.push({node->right, x + 1});
      }
    }

    vector<vector<int>> answer;
    for (int i = left; i <= right; i++) {
      answer.push_back(ret[i]);
    }

    return answer;
  }
};