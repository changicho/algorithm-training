#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  unordered_map<TreeNode*, TreeNode*> parents;
  unordered_map<TreeNode*, int> distances;

  void setParents(TreeNode* node) {
    if (node->left) {
      parents[node->left] = node;
      setParents(node->left);
    }
    if (node->right) {
      parents[node->right] = node;
      setParents(node->right);
    }
  }

  void setParents(TreeNode* node, int dist) {
    distances[node] = dist;

    if (node->left && !distances.count(node->left)) {
      setParents(node->left, dist + 1);
    }
    if (node->right && !distances.count(node->right)) {
      setParents(node->right, dist + 1);
    }
    if (parents[node] && !distances.count(parents[node])) {
      setParents(parents[node], dist + 1);
    }
  }

 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    setParents(root);
    setParents(target, 0);

    vector<int> answer;
    for (auto& it : distances) {
      TreeNode* node = it.first;
      int dist = it.second;

      if (dist == k) {
        answer.push_back(node->val);
      }
    }
    return answer;
  }
};