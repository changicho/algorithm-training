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
  struct Status {
    int count, leftRange, rightRange;
  };

  int answer = 0;

  // count, leftRange, rightRange
  Status recursive(TreeNode *node) {
    Status ret = {1, node->val, node->val};
    bool isFine = true;

    if (node->left) {
      Status range = recursive(node->left);
      if (range.count == -1 || ret.leftRange <= range.rightRange) {
        isFine = false;
      }

      ret.leftRange = min(ret.leftRange, range.leftRange);
      ret.rightRange = max(ret.rightRange, range.rightRange);
      ret.count += range.count;
    }
    if (node->right) {
      Status range = recursive(node->right);
      if (range.count == -1 || range.leftRange <= ret.rightRange) {
        isFine = false;
      }

      ret.leftRange = min(ret.leftRange, range.leftRange);
      ret.rightRange = max(ret.rightRange, range.rightRange);
      ret.count += range.count;
    }

    if (!isFine) return {-1, -1, -1};
    answer = max(answer, ret.count);
    return ret;
  }

 public:
  int largestBSTSubtree(TreeNode *root) {
    if (root) recursive(root);

    return answer;
  }
};