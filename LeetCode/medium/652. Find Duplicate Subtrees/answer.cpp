#include <algorithm>
#include <iostream>
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

// use preOrder and hash map

class Solution {
 private:
  unordered_set<string> preOrders;
  unordered_map<string, TreeNode *> um;

  string doPreOrder(TreeNode *node) {
    string ret = "(D";
    ret += to_string(node->val);

    if (node->left) ret += "L" + doPreOrder(node->left);
    if (node->right) ret += "R" + doPreOrder(node->right);
    ret += ")";

    if (preOrders.count(ret) > 0 && !um[ret]) {
      um[ret] = node;
    } else {
      preOrders.insert(ret);
    }

    return ret;
  }

 public:
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    vector<TreeNode *> answer;
    if (!root) return answer;

    doPreOrder(root);

    for (auto &it : um) {
      answer.push_back(it.second);
    }

    return answer;
  }
};