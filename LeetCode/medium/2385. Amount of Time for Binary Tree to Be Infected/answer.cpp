#include <algorithm>
#include <iostream>
#include <queue>
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

// use BFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  int amountOfTime(TreeNode *root, int start) {
    unordered_map<int, vector<int>> graph;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode *cur = q.front();
      q.pop();

      if (cur->left) {
        graph[cur->val].push_back(cur->left->val);
        graph[cur->left->val].push_back(cur->val);

        q.push(cur->left);
      }
      if (cur->right) {
        graph[cur->val].push_back(cur->right->val);
        graph[cur->right->val].push_back(cur->val);

        q.push(cur->right);
      }
    }

    queue<int> qVal;
    qVal.push(start);
    unordered_set<int> visited;
    visited.insert(start);

    int time = 0;
    while (!qVal.empty()) {
      int size = qVal.size();
      while (size--) {
        int cur = qVal.front();
        qVal.pop();

        for (int &next : graph[cur]) {
          if (visited.count(next)) continue;
          visited.insert(next);

          qVal.push(next);
        }
      }
      time++;
    }
    return time - 1;
  }
};

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Data {
    int depth, infectDepth;
  };

  int distance = 0;

  Data dfs(TreeNode *node, int start) {
    if (!node) return {0, 0};

    Data left = dfs(node->left, start);
    Data right = dfs(node->right, start);

    if (left.infectDepth != right.infectDepth) {
      int infectDepth = left.infectDepth > 0 ? right.depth + left.infectDepth
                                             : left.depth + right.infectDepth;
      distance = max(distance, infectDepth);
    }

    Data ret;
    ret.depth = max(left.depth, right.depth) + 1;
    ret.infectDepth = max(left.infectDepth, right.infectDepth);

    if (node->val == start || left.infectDepth != right.infectDepth) {
      ret.infectDepth++;
    }

    return ret;
  }

 public:
  int amountOfTime(TreeNode *root, int start) {
    auto [depth, inf_depth] = dfs(root, start);

    return max(distance, depth - inf_depth);
  }
};