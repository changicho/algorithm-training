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

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  int answer = 0;

  void recursive(TreeNode* node, int count) {
    answer = max(answer, count);

    if (node->right) {
      int nextCount = 1;
      if (node->val + 1 == node->right->val) {
        nextCount = count + 1;
      }
      recursive(node->right, nextCount);
    }
    if (node->left) {
      int nextCount = 1;
      if (node->val + 1 == node->left->val) {
        nextCount = count + 1;
      }
      recursive(node->left, nextCount);
    }
  }

 public:
  int longestConsecutive(TreeNode* root) {
    if (root) recursive(root, 1);
    return answer;
  }
};