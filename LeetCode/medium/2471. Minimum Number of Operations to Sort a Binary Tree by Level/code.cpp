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

// use BFS, sort, hash map
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  int calc(vector<int> &original) {
    int size = original.size();

    int ret = 0;
    vector<int> target = original;
    sort(target.begin(), target.end());

    unordered_map<int, int> indexes;
    for (int i = 0; i < size; i++) {
      indexes[original[i]] = i;
    }

    for (int i = 0; i < size; i++) {
      if (original[i] == target[i]) continue;

      int targetI = indexes[target[i]];
      indexes[original[i]] = targetI;
      swap(original[targetI], original[i]);

      ret++;
    }
    return ret;
  }

 public:
  int minimumOperations(TreeNode *root) {
    int answer = 0;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      vector<int> vals;
      while (size--) {
        TreeNode *cur = q.front();
        q.pop();

        vals.push_back(cur->val);

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }

      answer += calc(vals);
    }
    return answer;
  }
};