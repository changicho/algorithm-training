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

// use dynamic programming (bottom-up)
// time : O(2^(N/2))
// space : O(N * 2^(N/2))
class Solution {
 public:
  vector<TreeNode *> allPossibleFBT(int n) {
    // ignore case
    if (n % 2 == 0) {
      return {};
    }

    vector<TreeNode *> dp[21];

    dp[1].push_back(new TreeNode(0));
    for (int count = 3; count <= n; count += 2) {
      for (int leftCount = 1; leftCount < count - 1; leftCount += 2) {
        // one node will be root
        int rightCount = count - 1 - leftCount;

        for (TreeNode *leftRoot : dp[leftCount]) {
          for (TreeNode *rightRoot : dp[rightCount]) {
            TreeNode *root = new TreeNode(0, leftRoot, rightRoot);
            dp[count].push_back(root);
          }
        }
      }
    }

    return dp[n];
  }
};

// use dynamic programming (top-down)
// time : O(2^(N/2))
// space : O(N * 2^(N/2))
class Solution {
 private:
  unordered_map<int, vector<TreeNode *>> memo;

 public:
  vector<TreeNode *> allPossibleFBT(int n) {
    if ((n % 2) == 0) return {};

    if (memo.find(n) != memo.end()) {
      return memo[n];
    }

    // base case
    if (n == 1) {
      memo[1].push_back(new TreeNode());
      return memo[1];
    };

    vector<TreeNode *> res;
    for (int leftCount = 1; leftCount < n; leftCount += 2) {
      int rightCount = n - leftCount - 1;
      vector<TreeNode *> leftRoots = allPossibleFBT(leftCount);
      vector<TreeNode *> rightRoots = allPossibleFBT(rightCount);

      for (TreeNode *left : leftRoots) {
        for (TreeNode *right : rightRoots) {
          TreeNode *root = new TreeNode(0, left, right);
          res.push_back(root);
        }
      }
    }

    return memo[n] = res;
  }
};