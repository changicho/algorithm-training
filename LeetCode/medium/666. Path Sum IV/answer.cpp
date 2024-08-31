#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  int pathSum(vector<int>& nums) {
    int size = nums.size();
    vector<int> tree(100, -1);

    for (int& num : nums) {
      int d = num / 100;
      int l = (num % 100) / 10;
      int v = num % 10;

      int index = (1 << (d - 1)) - 1 + l;
      tree[index] = v;
    }

    int answer = 0;
    function<void(int, int)> recursive = [&](int node, int sum) {
      bool isLeaf = true;
      sum += tree[node];

      int left = node * 2, right = node * 2 + 1;
      if (tree[left] != -1) {
        recursive(left, sum);
        isLeaf = false;
      }
      if (tree[right] != -1) {
        recursive(right, sum);
        isLeaf = false;
      }

      if (isLeaf) {
        answer += sum;
      }
    };

    recursive(1, 0);
    return answer;
  }
};