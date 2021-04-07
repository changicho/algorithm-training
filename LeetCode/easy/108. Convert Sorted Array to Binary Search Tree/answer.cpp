#include <algorithm>
#include <iostream>
#include <queue>
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

struct Range {
  int start, end;
};

// BFS

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    int mid = (nums.size() - 1) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    queue<Range> q;
    q.push({0, mid - 1});
    q.push({mid + 1, (int)nums.size() - 1});

    while (!q.empty()) {
      Range cur = q.front();
      q.pop();

      if (cur.start > cur.end) continue;

      TreeNode* node = root;
      mid = (cur.start + cur.end) / 2;

      int val = nums[mid];
      while (true) {
        if (val < node->val) {
          if (!node->left) {
            node->left = new TreeNode(val);
            break;
          }
          node = node->left;
        } else {
          if (!node->right) {
            node->right = new TreeNode(val);
            break;
          }
          node = node->right;
        }
      }

      if (cur.start != cur.end) {
        q.push({cur.start, mid - 1});
        q.push({mid + 1, cur.end});
      }
    }

    return root;
  }
};

// use DFS

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
  }

  TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
  }
};