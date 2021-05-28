#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// use brute force

class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> answer;
    set<vector<int>> s;

    vector<int> array(n);
    for (int i = 0; i < n; i++) {
      array[i] = i + 1;
    }

    do {
      vector<int> tree(1000, 0);

      for (int num : array) {
        push(tree, num);
      }

      if (s.find(tree) != s.end()) continue;
      s.insert(tree);

      TreeNode* cur = convert(tree, n);

      answer.push_back(cur);
    } while (next_permutation(array.begin(), array.end()));

    return answer;
  }

  void push(vector<int>& tree, int num) {
    int index = 1;

    while (tree[index] != 0) {
      if (tree[index] < num) {
        index = index * 2 + 1;
      } else {
        index = index * 2;
      }
    }

    tree[index] = num;
  }

  TreeNode* convert(vector<int>& array, int limit) {
    vector<TreeNode*> nodes(array.size(), NULL);
    TreeNode* head = new TreeNode(array[1]);
    nodes[1] = head;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
      int i = q.front();
      q.pop();

      int left = i * 2;
      int right = i * 2 + 1;

      if (left >= array.size()) continue;

      if (array[left] != 0) {
        nodes[left] = new TreeNode(array[left]);
        nodes[i]->left = nodes[left];
        q.push(left);
      }
      if (array[right] != 0) {
        nodes[right] = new TreeNode(array[right]);
        nodes[i]->right = nodes[right];
        q.push(right);
      }
    }

    return head;
  }
};

// use recursive

class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    return generateSubTrees(1, n);
  }

  vector<TreeNode*> generateSubTrees(int start, int end) {
    if (start > end) return {NULL};
    if (start == end) return {new TreeNode(start)};
    vector<TreeNode*> res;

    vector<TreeNode*> leftSubTree, rightSubTree;

    for (int cur = start; cur <= end; cur++) {
      leftSubTree = generateSubTrees(start, cur - 1);
      rightSubTree = generateSubTrees(cur + 1, end);

      for (TreeNode* leftNode : leftSubTree) {
        for (TreeNode* rightNode : rightSubTree) {
          TreeNode* root = new TreeNode(cur);
          root->left = leftNode;
          root->right = rightNode;
          res.push_back(root);
        }
      }
    }
    return res;
  }
};

// use recursive & dp

class Solution {
 public:
  vector<TreeNode*> dp[9][9];

  vector<TreeNode*> generateTrees(int n) {
    return generateSubTrees(1, n);
  }

  vector<TreeNode*> generateSubTrees(int from, int to) {
    if (from > to) return {NULL};
    if (from == to) return {new TreeNode(from)};
    if (!dp[from][to].empty()) return dp[from][to];
    vector<TreeNode*> res;

    vector<TreeNode*> leftSubTree, rightSubTree;

    for (int cur = from; cur <= to; cur++) {
      leftSubTree = generateSubTrees(from, cur - 1);
      rightSubTree = generateSubTrees(cur + 1, to);

      for (TreeNode* leftNode : leftSubTree) {
        for (TreeNode* rightNode : rightSubTree) {
          TreeNode* root = new TreeNode(cur);
          root->left = leftNode;
          root->right = rightNode;
          res.push_back(root);
        }
      }
    }
    dp[from][to] = res;
    return res;
  }
};