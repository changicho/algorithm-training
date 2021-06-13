#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// use DFS

class Solution {
  vector<string> answer;

 public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> paths;
    recursive(root, paths);

    return answer;
  }

  void recursive(TreeNode *node, vector<string> paths) {
    if (!node) return;

    string val = to_string(node->val);
    paths.push_back(val);

    if (!node->left && !node->right) {
      answer.push_back(convert(paths));
      paths.pop_back();
      return;
    }

    if (node->left) recursive(node->left, paths);
    if (node->right) recursive(node->right, paths);

    paths.pop_back();
  }

  string convert(vector<string> &paths) {
    string ret = "";
    for (string s : paths) {
      ret += s + "->";
    }
    ret.erase(ret.length() - 2, 2);
    return ret;
  }
};