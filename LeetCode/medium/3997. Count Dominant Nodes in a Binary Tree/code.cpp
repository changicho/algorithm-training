#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

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
// space : O(H)
class Solution {
 private:
  int answer = 0;

  int dfs(TreeNode* node) {
    if (!node) return -1;
    int ret = node->val;

    int left = dfs(node->left);
    int right = dfs(node->right);

    ret = max({ret, left, right});
    if (ret == node->val) answer++;
    return ret;
  }

 public:
  int countDominantNodes(TreeNode* root) {
    if (root) dfs(root);

    return answer;
  }
};