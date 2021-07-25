#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// use path finding

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // step1. make hash map (key : child, value : parent)
    unordered_map<TreeNode*, TreeNode*> um;

    // step2. fill hashmap
    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
      TreeNode* cur = que.front();
      que.pop();

      if (!cur->left && !cur->right) continue;

      if (cur->left) {
        um[cur->left] = cur;
        que.push(cur->left);
      }
      if (cur->right) {
        um[cur->right] = cur;
        que.push(cur->right);
      }
    }

    // step3. find path of p, q from root
    TreeNode *pParent = p, *qParent = q;
    vector<TreeNode*> pPath, qPath;
    while (pParent) {
      pPath.emplace_back(pParent);
      pParent = um[pParent];
    }
    while (qParent) {
      qPath.emplace_back(qParent);
      qParent = um[qParent];
    }
    reverse(pPath.begin(), pPath.end());
    reverse(qPath.begin(), qPath.end());

    // step4. find branch point from root in pPath, qPath
    int limit = min(pPath.size(), qPath.size());
    TreeNode* answer = root;

    for (int i = 0; i < limit; i++) {
      if (pPath[i]->val != qPath[i]->val) break;
      answer = pPath[i];
    }

    return answer;
  }
};

// use post order

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *leftRet = NULL, *rightRet = NULL;

    if (root->val == p->val) return p;
    if (root->val == q->val) return q;

    if (root->left) leftRet = lowestCommonAncestor(root->left, p, q);

    if (root->right) rightRet = lowestCommonAncestor(root->right, p, q);

    if (leftRet && rightRet) return root;
    if (leftRet && !rightRet) return leftRet;
    if (!leftRet && rightRet) return rightRet;

    return NULL;
  }
};

// use euler tour

class Solution {
 private:
  vector<TreeNode*> eulerPaths;
  vector<int> levels;
  // key : node's value, value : index of path
  unordered_map<int, int> lastIndex;

  void eulerTour(TreeNode*& root, int level) {
    lastIndex[root->val] = eulerPaths.size();
    eulerPaths.emplace_back(root);
    levels.emplace_back(level);

    if (root->left) {
      eulerTour(root->left, level + 1);

      lastIndex[root->val] = eulerPaths.size();
      eulerPaths.emplace_back(root);
      levels.emplace_back(level);
    }
    if (root->right) {
      eulerTour(root->right, level + 1);

      lastIndex[root->val] = eulerPaths.size();
      eulerPaths.emplace_back(root);
      levels.emplace_back(level);
    }
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // step1. make euler path
    eulerTour(root, 0);

    // step2. set range
    int left = lastIndex[p->val];
    int right = lastIndex[q->val];
    if (left > right) swap(left, right);

    // step3. find LCA index
    int index = left;
    for (int i = left; i <= right; i++) {
      if (levels[i] < levels[index]) {
        index = i;
      }
    }

    TreeNode* node = eulerPaths[index];
    return node;
  }
};