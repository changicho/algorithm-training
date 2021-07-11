#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
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

// use BFS

// 시간 복잡도 : BFS하는데 O(N)
// 공간 복잡도 : BFS하는데 O(N)
class Solution {
 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    // 0. 전처리
    // 지운 노드들을 저장할 해시
    unordered_set<TreeNode*> removed_hash;
    unordered_set<int> hash_delete;
    // 지워야 할 노드를 빨리 찾기 위해 hash set으로 변경함
    for (int val : to_delete) {
      hash_delete.insert(val);
    }

    // 1. BFS를 이용해 순회하며
    // 자식만 비교하는 구조이므로 루트가 지워지는 경우 edge케이스 처리
    queue<TreeNode*> q;

    TreeNode* dummy = new TreeNode();
    dummy->left = root;

    q.push(dummy);

    while (!q.empty()) {
      TreeNode* cur = q.front();
      q.pop();

      // 2. 자식이 지워야할 노드인 경우, 지운 노드 hash set에 자식을 추가한 뒤 자식을 NULL로 바꿈
      // 이는 계층 구조이기 때문에 서브트리들의 루트가 될 가능성은 지워진 자식의 자식들만 이기 때문
      if (cur->left) {
        q.push(cur->left);
        // 지워야 하는 경우
        if (hash_delete.count(cur->left->val) > 0) {
          removed_hash.insert(cur->left);
          cur->left = NULL;
        }
      }
      if (cur->right) {
        q.push(cur->right);

        // 지워야 하는 경우
        if (hash_delete.count(cur->right->val) > 0) {
          removed_hash.insert(cur->right);
          cur->right = NULL;
        }
      }
    }

    // 3. 지운 자식 노드 hash set을 순회하며 서브트리의 루트가 될 수 있는경우 루트로 설정
    // 루트의 경우 edge 케이스 처리
    vector<TreeNode*> answer;
    if (removed_hash.count(root) == 0) answer.push_back(root);
    for (TreeNode* removed : removed_hash) {
      if (removed->left && removed_hash.count(removed->left) == 0) answer.push_back(removed->left);
      if (removed->right && removed_hash.count(removed->right) == 0) answer.push_back(removed->right);
    }

    return answer;
  }
};

// use DFS

class Solution {
 private:
  void recursive(TreeNode*& root, vector<TreeNode*>& answer, unordered_set<int>& hash_delete) {
    if (!root) return;

    recursive(root->left, answer, hash_delete);
    recursive(root->right, answer, hash_delete);

    if (hash_delete.count(root->val) > 0) {
      if (root->left) answer.push_back(root->left);
      if (root->right) answer.push_back(root->right);
      root = NULL;
      delete root;
    }
  }

 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> answer;
    unordered_set<int> hash_delete;

    for (int id : to_delete) {
      hash_delete.insert(id);
    }

    if (root && hash_delete.count(root->val) == 0) answer.push_back(root);
    recursive(root, answer, hash_delete);

    return answer;
  }
};