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

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<int> sums;

  int dfs(TreeNode *node) {
    int sum = node->val;

    if (node->left) {
      sum += dfs(node->left);
    }
    if (node->right) {
      sum += dfs(node->right);
    }

    sums.push_back(sum);

    return sum;
  }

 public:
  bool checkEqualTree(TreeNode *root) {
    int allSum = dfs(root);
    sums.pop_back();  // pop root sum
    if (abs(allSum % 2) == 1) return false;

    for (int &sum : sums) {
      if (sum == allSum) return true;
    }
    return false;
  }
};