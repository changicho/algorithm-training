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

// use left and right traversal
// time : O(N + Q)
// space : O(N + Q)
class Solution {
 private:
  int heights[100001];
  int maximum = 0;

  void leftToRight(TreeNode* node, int height) {
    if (!node) return;

    heights[node->val] = maximum;

    maximum = max(maximum, height);

    leftToRight(node->left, height + 1);
    leftToRight(node->right, height + 1);
  }

  void rightToLeft(TreeNode* node, int height) {
    if (!node) return;

    heights[node->val] = max(heights[node->val], maximum);

    maximum = max(height, maximum);

    rightToLeft(node->right, height + 1);
    rightToLeft(node->left, height + 1);
  }

 public:
  vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    maximum = 0;
    leftToRight(root, 0);
    maximum = 0;
    rightToLeft(root, 0);

    vector<int> answer;
    for (int& query : queries) {
      answer.emplace_back(heights[query]);
    }

    return answer;
  }
};