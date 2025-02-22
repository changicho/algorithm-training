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

// use DFS & hash set
// time : O(N)
// space : O(N)
class FindElements {
 private:
  unordered_set<int> us;

  void recursive(TreeNode *node, int cur) {
    us.insert(cur);

    if (node->left) {
      recursive(node->left, cur * 2 + 1);
    }
    if (node->right) {
      recursive(node->right, cur * 2 + 2);
    }
  }

 public:
  FindElements(TreeNode *root) { recursive(root, 0); }

  bool find(int target) { return us.count(target) > 0; }
};
