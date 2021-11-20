#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
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

// use leaf Erase DFS

class Solution {
  queue<TreeNode *> q;

  bool isLeaf(TreeNode *node) {
    if (!node->left && !node->right) {
      q.push(node);
      return true;
    }

    bool isLeftLeaf = node->left && isLeaf(node->left);
    bool isRightLeaf = node->right && isLeaf(node->right);

    if (isLeftLeaf) node->left = NULL;
    if (isRightLeaf) node->right = NULL;

    return false;
  }

 public:
  vector<vector<int>> findLeaves(TreeNode *root) {
    vector<vector<int>> answer;
    if (!root) return answer;

    bool isRootLeaf = false;

    while (!isRootLeaf) {
      vector<int> line;
      isRootLeaf = isLeaf(root);

      while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        line.push_back(cur->val);
      }

      answer.push_back(line);
    }

    return answer;
  }
};

// use sorting by depth

class Solution {
 private:
  struct Data {
    int depth;
    int val;

    bool operator<(const Data &b) const { return depth < b.depth; };
  };
  vector<Data> datum;

  int recursive(TreeNode *root) {
    // leaf node case
    if (!root->left && !root->right) {
      datum.push_back({0, root->val});
      return 0;
    }

    int leftDepth = 0, rightDepth = 0;

    if (root->left) leftDepth = recursive(root->left) + 1;
    if (root->right) rightDepth = recursive(root->right) + 1;

    int depth = max(leftDepth, rightDepth);
    datum.push_back({depth, root->val});
    return depth;
  }

 public:
  vector<vector<int>> findLeaves(TreeNode *root) {
    vector<vector<int>> answer;
    if (root) recursive(root);

    sort(datum.begin(), datum.end());

    int size = datum.back().depth;
    answer.resize(size + 1);

    for (Data &data : datum) {
      answer[data.depth].push_back(data.val);
    }

    return answer;
  }
};

// use DFS without sorting

class Solution {
 private:
  vector<vector<int>> answer;

  int recursive(TreeNode *root) {
    // leaf node case
    if (!root->left && !root->right) {
      if (answer.size() < 1) {
        answer.push_back({});
      }
      answer[0].push_back(root->val);
      return 0;
    }

    int leftDepth = 0, rightDepth = 0;

    if (root->left) leftDepth = recursive(root->left) + 1;
    if (root->right) rightDepth = recursive(root->right) + 1;

    int depth = max(leftDepth, rightDepth);
    if (answer.size() < depth + 1) {
      answer.push_back({});
    }
    answer[depth].push_back(root->val);
    return depth;
  }

 public:
  vector<vector<int>> findLeaves(TreeNode *root) {
    if (root) recursive(root);

    return answer;
  }
};

// use brute force with visited check

class Solution {
  unordered_set<TreeNode *> visited;
  vector<TreeNode *> leaves;  // leaves of current iteration

  void recursive(TreeNode *node) {
    bool hasLeft = node->left && visited.count(node->left) == 0;
    bool hasRight = node->right && visited.count(node->right) == 0;

    // if this node is leaf node
    if (!hasLeft && !hasRight) {
      visited.insert(node);
      leaves.push_back(node);
      return;
    }

    // visit children of node
    if (node->left && !visited.count(node->left)) recursive(node->left);
    if (node->right && !visited.count(node->right)) recursive(node->right);
  }

 public:
  vector<vector<int>> findLeaves(TreeNode *root) {
    vector<vector<int>> answer;
    if (!root) return answer;

    while (visited.count(root) == 0) {
      recursive(root);

      vector<int> currentLine;
      for (TreeNode *node : leaves) {
        currentLine.push_back(node->val);
      }

      answer.push_back(currentLine);
      leaves.resize(0);
    }
    return answer;
  }
};
