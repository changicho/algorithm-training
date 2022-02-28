#include <algorithm>
#include <iostream>
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
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Status {
    TreeNode *node;
    unsigned int x;
  };

 public:
  int widthOfBinaryTree(TreeNode *root) {
    int answer = 0;

    queue<Status> q;
    if (root) q.push({root, 1});

    while (!q.empty()) {
      int size = q.size();
      unsigned int left = q.front().x, right = q.front().x;

      while (size--) {
        Status cur = q.front();
        q.pop();

        right = cur.x;

        if (cur.node->left) q.push({cur.node->left, cur.x * 2});
        if (cur.node->right) q.push({cur.node->right, cur.x * 2 + 1});
      }

      answer = max(answer, (int)(right - left + 1));
    }

    return answer;
  }
};

// use DFS

class Solution {
 private:
  vector<int> lefts;  // [depth] = leftMostId

  int dfs(TreeNode *node, unsigned int id, int level) {
    if (!node) return 0;
    if (level >= lefts.size()) lefts.push_back(id);  // add left most node

    int fromLeft = 0, fromRight = 0, current = id + 1 - lefts[level];

    if (node->left) fromLeft = dfs(node->left, id * 2, level + 1);
    if (node->right) fromRight = dfs(node->right, id * 2 + 1, level + 1);

    return max({current, fromLeft, fromRight});
  }

 public:
  int widthOfBinaryTree(TreeNode *root) {
    int answer = dfs(root, 1, 0);

    return answer;
  }
};