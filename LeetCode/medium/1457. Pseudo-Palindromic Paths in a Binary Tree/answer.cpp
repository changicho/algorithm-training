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
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// use DFS with count
// time : O(N)
// space : O(N)
class Solution {
 private:
  int answer = 0;

  bool check(vector<int> &counts) {
    int odds = 0;
    for (int &num : counts) {
      if (num % 2 == 1) {
        odds++;
      }
    }

    if (odds < 2) return true;
    return false;
  }

  void recursive(TreeNode *node, vector<int> &counts) {
    bool isLeaf = true;

    if (node->left || node->right) isLeaf = false;

    if (isLeaf) {
      if (check(counts)) answer++;
      return;
    }

    if (node->left) {
      counts[node->left->val]++;
      recursive(node->left, counts);
      counts[node->left->val]--;
    }
    if (node->right) {
      counts[node->right->val]++;
      recursive(node->right, counts);
      counts[node->right->val]--;
    }
  }

 public:
  int pseudoPalindromicPaths(TreeNode *root) {
    if (!root) return 0;

    vector<int> counts(10);
    counts[root->val]++;

    recursive(root, counts);

    return answer;
  }
};