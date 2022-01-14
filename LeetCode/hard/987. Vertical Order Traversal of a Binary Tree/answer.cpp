#include <algorithm>
#include <iostream>
#include <map>
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

// use DFS with sort

class Solution {
 private:
  struct Data {
    int val, row, col;

    bool operator<(const Data &b) const {
      if (row != b.row) {
        return row < b.row;
      }
      return val < b.val;
    }
  };

  map<int, vector<Data>> lineByCol;

  void recursive(TreeNode *node, int col, int row) {
    lineByCol[col].push_back({node->val, row, col});

    if (node->left) {
      recursive(node->left, col - 1, row + 1);
    }
    if (node->right) {
      recursive(node->right, col + 1, row + 1);
    }
  }

 public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    if (root) recursive(root, 0, 0);

    vector<vector<int>> answer;
    for (auto &it : lineByCol) {
      vector<int> line;

      sort(it.second.begin(), it.second.end());
      for (Data &d : it.second) {
        line.push_back(d.val);
      }
      answer.push_back(line);
    }

    return answer;
  }
};