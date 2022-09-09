#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
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

// use DFS & sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Data {
    int val, count;

    bool operator<(const Data &b) { return count > b.count; }
  };

  unordered_map<int, int> counts;

  int recursive(TreeNode *node) {
    int sum = node->val;

    if (node->left) {
      sum += recursive(node->left);
    }
    if (node->right) {
      sum += recursive(node->right);
    }

    counts[sum]++;
    return sum;
  }

 public:
  vector<int> findFrequentTreeSum(TreeNode *root) {
    if (root) recursive(root);

    vector<Data> datas;
    for (auto &it : counts) {
      int key = it.first, val = it.second;

      datas.push_back({key, val});
    }

    sort(datas.begin(), datas.end());
    int freq = datas.front().count;
    vector<int> answer;
    for (Data &d : datas) {
      if (d.count < freq) break;
      answer.push_back(d.val);
    }
    return answer;
  }
};

// use DFS & counting sort
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Data {
    int val, count;

    bool operator<(const Data &b) { return count > b.count; }
  };

  unordered_map<int, int> counts;
  int freq = 0;

  int recursive(TreeNode *node) {
    int sum = node->val;

    if (node->left) {
      sum += recursive(node->left);
    }
    if (node->right) {
      sum += recursive(node->right);
    }

    counts[sum]++;
    freq = max(freq, counts[sum]);
    return sum;
  }

 public:
  vector<int> findFrequentTreeSum(TreeNode *root) {
    if (root) recursive(root);

    vector<int> answer;
    for (auto &it : counts) {
      int key = it.first, val = it.second;

      if (val == freq) answer.push_back(key);
    }

    return answer;
  }
};