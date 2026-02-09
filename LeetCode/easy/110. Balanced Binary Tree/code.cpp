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
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  int getHeight(TreeNode* cur, int height, bool& answer) {
    if (!cur) return height - 1;

    int left = getHeight(cur->left, height + 1, answer);
    int right = getHeight(cur->right, height + 1, answer);

    if (abs(left - right) > 1) answer = false;

    return max(left, right);
  }

 public:
  bool isBalanced(TreeNode* root) {
    bool answer = true;
    int height = getHeight(root, 0, answer);

    return answer;
  }
};

// DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool answer = true;

  int recursive(TreeNode* node) {
    if (!node) {
      return 0;
    }

    int left = recursive(node->left);
    int right = recursive(node->right);

    if (abs(left - right) > 1) {
      answer = false;
    }

    return max(left, right) + 1;
  }

 public:
  bool isBalanced(TreeNode* root) {
    recursive(root);
    return answer;
  }
};